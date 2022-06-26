#ifndef QCUSTOMBUTTON_H
#define QCUSTOMBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QColor>

enum class eMode{
    UNKNOWN = -1,

    OFF,
    ON
};

class QCustomToggleButton : public QPushButton
{
    Q_OBJECT

    public:
        QCustomToggleButton(QPixmap pixmap, QWidget* parent = nullptr);

        void setColor(eMode mode, QColor c);

    public slots:
        void onToggleAsked(bool state);

    protected:
        void paintEvent(QPaintEvent* e) override;

    private:
        QPixmap     m_pixmap;

        eMode       m_currentMode;

        QColor      m_onColor;
        QColor      m_offColor;
};

#endif // QCUSTOMBUTTON_H
