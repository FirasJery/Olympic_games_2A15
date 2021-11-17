#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reportage.h"
#include <qmessagebox.h>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "QFileDialog"
#include "QTextStream"
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView_reportA->setModel(R.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int cd = ui->lineEdit_codeR->text().toInt();
    int cdC= ui->lineEdit_codeCMod->text().toInt();
    QString ed = ui->lineEdit_editeur->text();
    QString s =ui->lineEdit_source->text();
    QString cnt=ui->lineEdit_report->text();
    QString d = ui->lineEdit_date->text();
    Reportage R(cd, cdC, ed, s, d, cnt);

    bool test = R.ajouter();
    QMessageBox msgBox;

    if(test)
       {
           msgBox.setText("Ajout avec succes.");
           ui->tableView_reportA->setModel(R.afficher());
       }
    else
          msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pushButton_supp_clicked()
{
    Reportage R1; R1.setcode(ui->lineEdit_codeRA->text().toInt());
    bool test = R1.supprimer(R1.getcode());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression avec succes.");
    ui->tableView_reportA->setModel(R.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}


void MainWindow::on_pushButton_modifier_clicked()
{
    int cd= ui->lineEdit_codeMod->text().toInt();
    int cdC= ui->lineEdit_codeCMod->text().toInt();
    QString ed = ui->lineEdit_editeurM->text();
    QString s =ui->lineEdit_sourceM->text();
    QString cnt=ui->lineEdit_reportM->text();
    QString d = ui->lineEdit_dateM->text();
    Reportage R(cd, cdC, ed, s, d, cnt);

    bool test = R.modifier();
    QMessageBox msgBox;

    if(test)
       {
           msgBox.setText("Modifier avec succes.");
           ui->tableView_reportA->setModel(R.afficher());
       }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}


void MainWindow::on_comboBox_trier_activated(QString a)
{
   a = ui->comboBox_trier->currentText();

              int  i=0;
            if(a == "Editeur")
                i=1;
            else if (a == "Source")
                i=2;
            else if (a == "Date")
            {
                i=3;
            }

    ui->tableView_reportA->setModel(R.trier(i));

}

void MainWindow::on_pushButton_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_reportA->model()->rowCount();
    const int columnCount = ui->tableView_reportA->model()->columnCount();
    out <<  "<html>\n"
               "<head>\n"
       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
       <<  QString("<title>%1</title>\n").arg("strTitle")
       <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

      //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Liste Des Offres </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
       if (!ui->tableView_reportA->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->tableView_reportA->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

                                               // data table
               for (int row = 0; row < rowCount; row++) {
                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                  for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_reportA->isColumnHidden(column)) {
         QString data = ui->tableView_reportA->model()->data(ui->tableView_reportA->model()->index(row, column)).toString().simplified();
         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                       }
                                                   }
                          out << "</tr>\n";
                                               }
                                out <<  "</table> </center>\n"
                                        "</body>\n"
                                      "</html>\n";
          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}

