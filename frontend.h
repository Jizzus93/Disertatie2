#ifndef FRONTEND_H
#define FRONTEND_H

#include <annotationentry.h>
#include <annotation.h>

#include <QMainWindow>
#include <QAction>

namespace Ui {
class Frontend;
}

class Frontend : public QMainWindow
{
    Q_OBJECT

public:
    explicit Frontend(QWidget *parent = 0);
    ~Frontend();

private slots:
    void on_annotateButton_clicked();

    void on_actionQuit_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_2_triggered();

    void on_actionLoad_triggered();

private:
    QList<AnnotationEntry> m_annotation;
    Ui::Frontend *ui;
};

#endif // FRONTEND_H
