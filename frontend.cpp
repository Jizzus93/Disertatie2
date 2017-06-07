#include "frontend.h"
#include "ui_frontend.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QMenu>

Frontend::Frontend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Frontend)
{
    ui->setupUi(this);
}

Frontend::~Frontend()
{
    delete ui;
}

void Frontend::on_annotateButton_clicked()
{
    QString selectedText = ui->textEdit->textCursor().selectedText();
    int selectionStart = ui->textEdit->textCursor().selectionStart();
    int selectionEnd = ui->textEdit->textCursor().selectionEnd();
    QString offset = QString("\nStartOffset: %1 \nEndOffset: %2\n").arg(selectionStart).arg(selectionEnd);
    selectedText += offset;

    QMessageBox::critical(this,tr("info"), selectedText);

}

void Frontend::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

void Frontend::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void Frontend::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                // error message
            } else {
                QTextStream stream(&file);
                stream << ui->textEdit->toPlainText();
                stream.flush();
                file.close();
            }
        }
}

void Frontend::on_actionSave_2_triggered()
{
    //TODO: IMPLEMENT
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                tr("JSON Files (*.json);;BIN Files (*.dat)"));
    Annotation annotation;
    annotation.setEntryList(this->m_annotation);
    annotation.saveAnnotation(Annotation::Json, fileName);
}

void Frontend::on_actionLoad_triggered()
{
    //TODO: IMPLEMENT
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load File"), QString(),
                tr("JSON Files (*.json);;BIN Files (*.dat)"));
    Annotation annotation;
    annotation.loadAnnotation(Annotation::Json, fileName);
    this->m_annotation = annotation.getEntryList();

}

void Frontend::on_textEdit_selectionChanged()
{
    QTextCursor tc = ui->textEdit->textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    QString word = tc.selectedText();
    int selectionStart = tc.selectionStart();
    int selectionEnd = tc.selectionEnd();

    QTextCharFormat fmt;
    fmt.setBackground(Qt::yellow);

    QTextCursor cursor(ui->textEdit->document());
    cursor.setPosition(selectionStart, QTextCursor::MoveAnchor);
    cursor.setPosition(selectionEnd, QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);
}
