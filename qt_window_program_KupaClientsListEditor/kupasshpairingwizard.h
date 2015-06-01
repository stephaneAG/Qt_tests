/* KupaSSHPairingWizard.h
 *
 * KSPW - Kupa SSH pairing wizard 
 *
 * Simple tool to ease the creation of SSH keys & make it more user-friendly
 *
*/

#include <QtGui>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

class KupaSSHPairingWizard : public QWizard
{
  Q_OBJECT

  public:
	  //KupaSSHPairingWizard();
	  KupaSSHPairingWizard(QWidget *parent = 0); // if I'm right, this constructor allows 'not being parented' if not params are passed, and 'parented' if we pass a 'this' from a class for ex (?)

  private:
	  QWizardPage *createIntroPage();
	  QWizardPage *createRegistrationPage();
	  QWizardPage *createConclusionPage();

};
