#include "QCustomToggleButton.h"

#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>

QCustomToggleButton::QCustomToggleButton(QPixmap pixmap, QWidget* parent)
    : QPushButton(parent),
      m_pixmap(pixmap),
      m_currentMode(eMode::UNKNOWN)
{
    this->setCheckable(true);
    this->setFlat(true);

    setMinimumSize(m_pixmap.width() + 4, pixmap.height() + 4);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_currentMode = eMode::OFF;
}

void QCustomToggleButton::setColor(eMode mode, QColor c)
{
    switch (mode)
    {
        case eMode::ON:
        {
            m_onColor = c;
            break;
        }

        case eMode::OFF:
        {
            m_offColor = c;
            break;
        }

        case eMode::UNKNOWN:
        default:
            break;
    }
}


void QCustomToggleButton::onToggleAsked(bool state)
{
    Q_UNUSED(state);

    m_currentMode = (m_currentMode == eMode::OFF) ? eMode::ON : eMode::OFF;

    repaint();
}

/******************
*    PROTECTED    *
******************/

void QCustomToggleButton::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);

    QStyleOption opt;
    opt.init(this);

    QColor currentColor = (m_currentMode == eMode::OFF) ? m_offColor : m_onColor;

    QPen pen;
    pen.setWidth(2);
    pen.setColor(currentColor);

    QPainter p(this);
    p.setPen(pen);
    p.setRenderHint(QPainter::Antialiasing);
    p.setBrush(Qt::BrushStyle::NoBrush);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

	QRect content = this->contentsRect();
	content.setLeft(content.left() + 1);
	content.setRight(content.right() - 1);
	content.setTop(content.top() + 1);
	content.setBottom(content.bottom() - 1);

	p.drawEllipse(content);

	QRect pixmapRect(m_pixmap.rect());
	pixmapRect.moveCenter(content.center());

	p.save();

	QPainter pixmapPainter(&m_pixmap);

	pixmapPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	pixmapPainter.setPen(currentColor);
	pixmapPainter.setBrush(currentColor);

	pixmapPainter.drawRect(pixmapRect);

	pixmapPainter.end();

	p.restore();

	p.drawPixmap(pixmapRect, m_pixmap);
}
