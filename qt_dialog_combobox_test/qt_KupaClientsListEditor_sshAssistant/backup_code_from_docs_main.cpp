#include <QtGui>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

QWizardPage *createIntroPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("Introduction");

  QLabel *label = new QLabel("This wizard will help you register your copy "
                                "of Super Product Two.");
  label->setWordWrap(true);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  page->setLayout(layout);

  return page;
}

QWizardPage *createRegistrationPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("Registration");
  page->setSubTitle("Please fill both fields.");

  QLabel *nameLabel = new QLabel("Name:");
  QLineEdit *nameLineEdit = new QLineEdit;

  QLabel *emailLabel = new QLabel("Email address:");
  QLineEdit *emailLineEdit = new QLineEdit;

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(nameLabel, 0, 0);
  layout->addWidget(nameLineEdit, 0, 1);
  layout->addWidget(emailLabel, 1, 0);
  layout->addWidget(emailLineEdit, 1, 1);
  page->setLayout(layout);

  return page;
}

QWizardPage *createConclusionPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("Conclusion");

  QLabel *label = new QLabel("You are now successfully registered. Have a "
                                "nice day!");
  label->setWordWrap(true);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  page->setLayout(layout);

  return page;
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QString translatorFileName = QLatin1String("qt_");
  translatorFileName += QLocale::system().name();
  QTranslator *translator = new QTranslator(&app);
  if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    app.installTranslator(translator);

  QWizard wizard;
  wizard.addPage(createIntroPage());
  wizard.addPage(createRegistrationPage());
  wizard.addPage(createConclusionPage());

  wizard.setWindowTitle("KSPW - Kupa SSH pairing wizard");
  wizard.show();

  return app.exec();
}
