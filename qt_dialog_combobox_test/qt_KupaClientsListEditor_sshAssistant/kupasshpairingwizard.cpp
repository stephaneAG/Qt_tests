/* kupasshpairingwizard.cpp */

#include "kupasshpairingwizard.h"

/* the SSHH pairing Wizard constructor */
KupaSSHPairingWizard::KupaSSHPairingWizard()
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

  QLabel *label = new QLabel("This wizard will help you register your copy "
		                                    "of Super Product Two.");
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

/* fcn to create the final page, informing the user that the key has been generated & is available */
QWizardPage *KupaSSHPairingWizard::createConclusionPage()
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
