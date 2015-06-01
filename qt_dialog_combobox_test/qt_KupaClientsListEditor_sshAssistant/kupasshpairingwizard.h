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
	  KupaSSHPairingWizard();

  private:
	  QWizardPage *createIntroPage();
	  QWizardPage *createRegistrationPage();
	  QWizardPage *createConclusionPage();

};
