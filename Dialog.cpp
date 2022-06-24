#include "Dialog.h"

#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
      m_firstButton(nullptr),
      m_secondButton(nullptr)
{
    setStyleSheet("background-color: white; border 1px solid red;");

    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    // to fix taskbar minimize feature
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    //setAttribute(Qt::WA_TranslucentBackground, true);

    setWindowTitle("TEST");

    initLayout();

    if (nullptr != m_firstButton)
        connect(m_firstButton, SIGNAL(toggled(bool)), m_firstButton, SLOT(onToggleAsked(bool)));

    if (nullptr != m_secondButton)
        connect(m_secondButton, SIGNAL(toggled(bool)), m_secondButton, SLOT(onToggleAsked(bool)));
}

Dialog::~Dialog()
{

}

/******************
*     PRIVATE     *
******************/

void Dialog::initLayout()
{
    setContentsMargins(20,20,20,20);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(5);

    QPixmap firstPixmap("Valide/2x/baseline_check_circle_black_24dp.png");
    m_firstButton = new QCustomToggleButton(firstPixmap);
    m_firstButton->setColor(eMode::OFF, QColor("#C6C6C6"));
    m_firstButton->setColor(eMode::ON, QColor("#1ABA22"));

    QPixmap secondPixmap("Corbeille/2x/baseline_delete_black_24dp.png");
    m_secondButton = new QCustomToggleButton(secondPixmap);
    m_secondButton->setColor(eMode::OFF, QColor("#C6C6C6"));
    m_secondButton->setColor(eMode::ON, QColor("#BA1A1A"));

    mainLayout->addWidget(m_firstButton);
    mainLayout->addWidget(m_secondButton);

    setLayout(mainLayout);
}
