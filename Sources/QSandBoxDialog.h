#ifndef QSANDBOXDIALOG_H
#define QSANDBOXDIALOG_H

#include <QDialog>

#include "QCustomToggleButton.h"

class QSandBoxDialog : public QDialog
{
        Q_OBJECT

    public:
        QSandBoxDialog(QWidget *parent = 0);
        ~QSandBoxDialog();

    private:
        void initLayout();

    private:
        QCustomToggleButton*    m_firstButton;
        QCustomToggleButton*    m_secondButton;
};

#endif // QSANDBOXDIALOG_H
