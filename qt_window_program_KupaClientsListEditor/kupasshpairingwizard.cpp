/* kupasshpairingwizard.cpp */

#include "kupasshpairingwizard.h"

/* the SSHH pairing Wizard constructor */
KupaSSHPairingWizard::KupaSSHPairingWizard(QWidget*) // testing the constructor with a specified 'no parent' parameter, to see if it allows runnig the wizard while still being able to use KCLE
/*KupaSSHPairingWizard::KupaSSHPairingWizard()*/
{
  // have the wizard create & add its pages to itself on creation
  this->addPage(createIntroPage());
  this->addPage(createRegistrationPage());
  this->addPage(createConclusionPage());

  // have it name itself
  this->setWindowTitle("KSPW - Kupa SSH pairing wizard");
}

/* fcn to create the intro page */
QWizardPage *KupaSSHPairingWizard::createIntroPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("Introduction");

  QLabel *label = new QLabel("This wizard will help you generate your public ssh key for Kupa clients"
		             "\n"
			     "Use it when setting up a new Kupa client to complete the 'server' part."
			     "You 'll still need to configure the Kupa settings on the remote operating system for the Kupa pairing to be complete."
		             "\n"
			     "\n"
		             "Not Using Kupa ?"
			     "This tool can still be used as a GUI to generate any SSH key: the underlying operating system commands are used to do the work behind the curtain. "
			     "\n"
			     "Enjoy!");
  label->setWordWrap(true);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  page->setLayout(layout);

  return page;
}

/* fcn to create the 'middle' page, where we request infos & after what we do stuff */
QWizardPage *KupaSSHPairingWizard::createRegistrationPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("SSH keygen settings");
  page->setSubTitle("Please fill all the fields, else you may ecounter errors.");

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

/* fcn to create the final page, informing the user that the key has been generated & is available */
QWizardPage *KupaSSHPairingWizard::createConclusionPage()
{
  QWizardPage *page = new QWizardPage;
  page->setTitle("Congratulations !");

  QLabel *label = new QLabel("You public key has been successfully generated."
		             "\n" 
		             "You will find it in the directory you specified."
			     "Your private key has also been update as well, allowing the connection from the remote computer."
			     "You still have to add the new client to the clients list ( the settings.kupa file ), easily editable using KCLE"
			     "You still need to configure the Kupa settings on the remote operating system for the Kupa pairing to operate correctly"
			     "\n"
			     "Note that you can also setup a one-way-only SSH pairing, the choice is up to you"
			     "\n"
			     "Now, make use of Kupa ! :)");
  label->setWordWrap(true);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  page->setLayout(layout);

  return page;
}
