#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<competition.h>
#include <QMessageBox>
#include<QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QStringList list=(QStringList()<<"course"<<"saut"<<"natation");
    ui->comboBox->addItems(list);
    ui->tableView->setModel(ajtmp.afficher());
   // ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString nom=ui->l_nom->text();
    QString lieu=ui->l_lieu->text();
    QDate date_d= ui->d_d->date();
        qDebug() << "Date Selected: " << date_d;

        QDate date_f= ui->d_f->date();
            qDebug() << "Date Selected: " << date_f;
    QString desc=ui->text_desc->toPlainText();
    QString cb = ui->comboBox->currentText();
    competition R(nom, lieu, desc,cb,date_d, date_f);
                bool test=R.ajouter();
                ui->tableView->setModel(ajtmp.afficher());
                QMessageBox msgBox;
                if (test)
                {
                    ui->tableView->setModel(ajtmp.afficher());
                    msgBox.setText("Ajout avec succés.");
                    msgBox.exec();
                }

}

void MainWindow::on_pushButton_2_clicked()
{QMessageBox msgBox ;
    int cc = ui->id->text().toInt();
        bool test=ajtmp.supprimer(cc);
        if(test)
        {ui->tableView->setModel(ajtmp.afficher());//refresh
            /*QMessageBox::information(nullptr, QObject::tr("Supprime un dossier"),
                        QObject::tr(" Dossier supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel)*/
            msgBox.setText(" supprimé.");
            msgBox.exec();

        }
        else
        {QMessageBox::critical(nullptr, QObject::tr("Supprimer failed "),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

        QSqlQuery qry;
        qry.prepare("select * from COMPETITIONS where CODE_COMPETITION='"+val+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->id->setText(qry.value(0).toString());

                ui->l_nom->setText(qry.value(1).toString());
                ui->l_lieu->setText(qry.value(2).toString());
                ui->d_d->setDate(qry.value(3).toDate());
                ui->d_f->setDate(qry.value(4).toDate());
                ui->text_desc->setText(qry.value(5).toString());
                ui->comboBox->setEditText(qry.value(6).toString());





            }
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();


             switch (ui->comboBox_2->currentIndex()) {
             case 0:
                 model->setQuery("select * from COMPETITIONS order by NOM ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCR"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
                 break;
             case 1:
                 model->setQuery("select * from COMPETITIONS order by CODE_COMPETITION ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCR"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
                 break;
             case 2:
                 model->setQuery("select * from COMPETITIONS order by DATE_DE ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_COMPETITION"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCR"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));
                 break;
             }
             ui->tableView->setModel(model);
             ui->tableView->show();
             msgBox.setText("Tri avec succés.");
             msgBox.exec();
}



void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(ajtmp.afficher());
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString code=ui->id->text();
        QString nom=ui->l_nom->text();
        QString lieu=ui->l_lieu->text();
        QDate date_d= ui->d_d->date();
            qDebug() << "Date Selected: " << date_d;

            QDate date_f= ui->d_f->date();
                qDebug() << "Date Selected: " << date_f;
        QString desc=ui->text_desc->toPlainText();
        QString cb = ui->comboBox->currentText();

        competition dos;
        bool test=dos.modifier(nom,lieu,desc,cb,date_d,date_f,code);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView->setModel(dos.afficher());
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();}

}
void MainWindow::PrintWidget(QWidget* widget) {

  QPixmap pix(widget->size());
  QPainter painter(&pix);
  widget->render(&painter);
  painter.end();
  QPrinter printer(QPrinter::HighResolution);
  printer.setOrientation(QPrinter::Landscape);
  printer.setOutputFormat(QPrinter::PdfFormat);
  printer.setPaperSize(QPrinter::A4);
  printer.setOutputFileName("C:/Users/Firas/Desktop/myfile.pdf"); // will be in build folder

  painter.begin(&printer);
  double xscale = printer.pageRect().width() / double(pix.width());
  double yscale = printer.pageRect().height() / double(pix.height());
  double scale = qMin(xscale, yscale);
  painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                    printer.paperRect().y() + printer.pageRect().height() / 2);
  painter.scale(scale, scale);
  painter.translate(-widget->width() / 2, -widget->height() / 2);
  painter.drawPixmap(0, 0, pix);

QTextDocument doc;

doc.setHtml("htmlcontent");
doc.drawContents(&painter);

  painter.end();
}


void MainWindow::on_pushButton_6_clicked()
{
    PrintWidget(ui->tableView) ;
}

void MainWindow::on_rech_textChanged(const QString &arg1)
{
     ui->tableView->setModel(ajtmp.recherche(arg1));
}

void MainWindow::on_pushsendO_clicked()
{
    smtpo = new Smtp("gestion.recs@gmail.com" , "gestiongestion", "smtp.gmail.com",465);
    connect(smtpo, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msgo=ui->plainO->toPlainText();

    smtpo->sendMail("firas_test",ui->mailO->text(),ui->objetO->text(),msgo);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sent Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
