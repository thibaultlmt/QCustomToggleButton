#include "QSandBoxDialog.h"

#include <QApplication>
#include <QFontDatabase>
#include <QFile>

int main(int argc, char *argv[])
{
    // Init QRC file
    Q_INIT_RESOURCE(resources);

    QCoreApplication::setApplicationName("Color Sample");
    QCoreApplication::setOrganizationName("@thibaultlmt");
    QCoreApplication::setOrganizationDomain("https://www.instagram.com/thibaultlmt");

    QApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/Fonts/Poppins-Black");
    QFontDatabase::addApplicationFont(":/Fonts/Poppins-Medium");
    QFontDatabase::addApplicationFont(":/Fonts/Poppins-Regular");
    QFontDatabase::addApplicationFont(":/Fonts/Poppins-SemiBold");

    QFile styleSheet(":/Style/style.css");
    QString style = "";

    if (styleSheet.open(QFile::ReadOnly))
        style = QLatin1String(styleSheet.readAll());

    app.setStyleSheet(style);

    QSandBoxDialog* sandBoxDlg = new QSandBoxDialog();

    QString iconPath = ":/AppIcon/appIcon";

    sandBoxDlg->setWindowTitle("Color Sample");
    sandBoxDlg->setWindowIcon(QIcon(iconPath));
    sandBoxDlg->setAttribute(Qt::WA_DeleteOnClose);
    sandBoxDlg->setFixedSize(240,114);
    sandBoxDlg->show();

    return app.exec();
}
