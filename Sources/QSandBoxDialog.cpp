#include "QSandBoxDialog.h"

#include <QHBoxLayout>

QSandBoxDialog::QSandBoxDialog(QWidget *parent)
    : QDialog(parent),
      m_firstButton(nullptr),
      m_secondButton(nullptr)
{
    Qt::WindowFlags flags = Qt::Dialog
                | Qt::WindowTitleHint
                | Qt::WindowSystemMenuHint
                | Qt::WindowMinimizeButtonHint
                | Qt::WindowCloseButtonHint
                | Qt::CustomizeWindowHint;

    flags = flags & ~Qt::Window;

    setWindowFlags(flags);
    setFocus();

    initLayout();

    if (nullptr != m_firstButton)
        connect(m_firstButton, SIGNAL(toggled(bool)), m_firstButton, SLOT(onToggleAsked(bool)));

    if (nullptr != m_secondButton)
        connect(m_secondButton, SIGNAL(toggled(bool)), m_secondButton, SLOT(onToggleAsked(bool)));
}

QSandBoxDialog::~QSandBoxDialog()
{

}

/******************
*     PRIVATE     *
******************/

void QSandBoxDialog::initLayout()
{
    setContentsMargins(20,20,20,20);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(5);

    QPixmap firstPixmap(":/Icons/valid");
    m_firstButton = new QCustomToggleButton(firstPixmap);
    m_firstButton->setColor(eMode::OFF, QColor("#C6C6C6"));
    m_firstButton->setColor(eMode::ON, QColor("#1ABA22"));

    QPixmap secondPixmap(":/Icons/trash");
    m_secondButton = new QCustomToggleButton(secondPixmap);
    m_secondButton->setColor(eMode::OFF, QColor("#C6C6C6"));
    m_secondButton->setColor(eMode::ON, QColor("#BA1A1A"));

    mainLayout->addWidget(m_firstButton);
    mainLayout->addWidget(m_secondButton);

    setLayout(mainLayout);
}
