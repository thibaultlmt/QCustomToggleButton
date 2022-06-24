#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "QCustomToggleButton.h"

class Dialog : public QDialog
{
        Q_OBJECT

    public:
        Dialog(QWidget *parent = 0);
        ~Dialog();

    private:
        void initLayout();

    private:
        QCustomToggleButton*    m_firstButton;
        QCustomToggleButton*    m_secondButton;
};

#endif // DIALOG_H
