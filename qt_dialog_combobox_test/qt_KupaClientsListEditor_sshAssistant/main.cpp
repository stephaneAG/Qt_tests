#include <QtGui>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

/* include the freshly created "KSPW - Kupa SSH pairing wizard" class */
#include "kupasshpairingwizard.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QString translatorFileName = QLatin1String("qt_");
  translatorFileName += QLocale::system().name();
  QTranslator *translator = new QTranslator(&app);
  if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    app.installTranslator(translator);

  KupaSSHPairingWizard ksshpwizard; // create an instance of the Kupa SSH pairing wizard
  ksshpwizard.show();

  return app.exec();
}
