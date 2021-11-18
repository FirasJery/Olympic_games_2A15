#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsors.h"
#include<QTextStream>
#include<QDate>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Stmp.Afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonajout_clicked()
{
    bool test;
    int id = ui->lineid->text().toInt();
    QString nom= ui->linenom->text();
    int budget = ui->linebudget->text().toInt();
    QString type;
    if (budget >= 10000)
     type= "Gold";
    else type ="Normal";
    int etat = ui->lineetat->text().toInt();
    int codec = ui->linecomp->text().toInt();
    SPONSORS S(id,nom,type,codec,budget,etat);
    test=S.Ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->tableView->setModel(Stmp.Afficher());
}

void MainWindow::on_pushButtonsupp_clicked()
{
    int id = ui->lineid->text().toInt();
    bool test=Stmp.Supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("supp successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("supp failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->tableView->setModel(Stmp.Afficher());

}

void MainWindow::on_pushButtonmodif_clicked()
{
    int id = ui->lineid->text().toInt();
    QString nom= ui->linenom->text();
    int budget = ui->linebudget->text().toInt();
    QString type;
    if (budget >= 10000)
     type= "Gold";
    else type ="Normal";
    int etat = ui->lineetat->text().toInt();
    int codec = ui->linecomp->text().toInt();
    SPONSORS S(id,nom,type,codec,budget,etat);
    bool test=S.Modifier(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modif successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("modif failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->tableView->setModel(Stmp.Afficher());

}

void MainWindow::on_pushButtonmodif_3_clicked()
{
    QString tst;
       if (ui->radioButton->isChecked()) tst="ASC";
       else if (ui->radioButton_2->isChecked()) tst="DESC";

       switch (ui->comboBox->currentIndex()) {
       case 0:
           ui->tableView->setModel(Stmp.Triparnom(tst));
           break;
       case 1:
           ui->tableView->setModel(Stmp.TriEtat(tst));
           break;
       case 2:
           ui->tableView->setModel(Stmp.TriBudget(tst));
           break;
       }
   }




void MainWindow::on_linebudget_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(Stmp.recherche(arg1));
}

void MainWindow::on_pushButtonmodif_2_clicked()
{
    bool test =Stmp.Export(ui->linebudget_3->text());

    if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Export effectué\n""Click Ok to exit."), QMessageBox::Ok);
        }
        else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Export non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    if (Stmp.alerte()>0)
            {
                QString notif=QString::number(Stmp.alerte())+" Frais non encore deposés.\n""Click Ok to exit.";
                QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
            }
    else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Tous les frais sont deposés\n""Click Ok to exit."), QMessageBox::Ok);
}



void MainWindow::on_pushButtonmodif_4_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount = ui->tableView->model()->columnCount();
                    QString TT = QDate::currentDate().toString("dd/MM/yyyy");
                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        << "<title>SPONSORS<title>\n "
                        << "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong>  SPONSORS  "+TT+"</strong></h1>"
                        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                          "</br> </br>";

                    out << "<thead><tr bgcolor=#d6e5ff>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";


                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView->isColumnHidden(column)) {
                                QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;

                    QPrintDialog *test = new QPrintDialog(&printer, NULL);
                    if (test->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;
}
