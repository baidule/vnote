#ifndef VSETTINGSDIALOG_H
#define VSETTINGSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>

class QDialogButtonBox;
class QComboBox;
class QGroupBox;
class QDoubleSpinBox;
class QCheckBox;
class VLineEdit;
class QStackedLayout;
class QListWidget;
class QPlainTextEdit;
class QVBoxLayout;

class VGeneralTab : public QWidget
{
    Q_OBJECT
public:
    explicit VGeneralTab(QWidget *p_parent = 0);
    bool loadConfiguration();
    bool saveConfiguration();

private:
    QLayout *setupStartupPagesLayout();

    bool loadLanguage();
    bool saveLanguage();

    bool loadSystemTray();
    bool saveSystemTray();

    bool loadStartupPageType();
    bool saveStartupPageType();

    // Language
    QComboBox *m_langCombo;

    // System tray
    QCheckBox *m_systemTray;

    // Startup page type.
    QComboBox *m_startupPageTypeCombo;

    // Startup pages.
    QPlainTextEdit *m_startupPagesEdit;

    // Startup pages add files button.
    QPushButton *m_startupPagesAddBtn;

    static const QVector<QString> c_availableLangs;
};

class VReadEditTab : public QWidget
{
    Q_OBJECT
public:
    explicit VReadEditTab(QWidget *p_parent = 0);
    bool loadConfiguration();
    bool saveConfiguration();

private:
    bool loadWebZoomFactor();
    bool saveWebZoomFactor();

    bool loadSwapFile();
    bool saveSwapFile();

    bool loadAutoSave();
    bool saveAutoSave();

    void showTipsAboutAutoSave();

    // Web zoom factor.
    QCheckBox *m_customWebZoom;
    QDoubleSpinBox *m_webZoomFactorSpin;

    // Swap file.
    QCheckBox *m_swapFile;

    // Auto save.
    QCheckBox *m_autoSave;

    QGroupBox *m_readBox;
    QGroupBox *m_editBox;
};

class VNoteManagementTab : public QWidget
{
    Q_OBJECT
public:
    explicit VNoteManagementTab(QWidget *p_parent = 0);
    bool loadConfiguration();
    bool saveConfiguration();

private slots:
    void customImageFolderChanged(int p_state);
    void customImageFolderExtChanged(int p_state);
    void customAttachmentFolderChanged(int p_state);

private:
    bool loadImageFolder();
    bool saveImageFolder();

    bool loadImageFolderExt();
    bool saveImageFolderExt();

    bool loadAttachmentFolder();
    bool saveAttachmentFolder();

    QGroupBox *m_noteBox;
    QGroupBox *m_externalBox;

    // Image folder.
    QCheckBox *m_customImageFolder;
    VLineEdit *m_imageFolderEdit;

    // Image folder of External File.
    QCheckBox *m_customImageFolderExt;
    VLineEdit *m_imageFolderEditExt;

    // Attachment folder.
    QCheckBox *m_customAttachmentFolder;
    VLineEdit *m_attachmentFolderEdit;
};

class VMarkdownTab : public QWidget
{
    Q_OBJECT
public:
    explicit VMarkdownTab(QWidget *p_parent = 0);
    bool loadConfiguration();
    bool saveConfiguration();

private:
    bool loadOpenMode();
    bool saveOpenMode();

    bool loadHeadingSequence();
    bool saveHeadingSequence();

    bool loadColorColumn();
    bool saveColorColumn();

    // Default note open mode for markdown.
    QComboBox *m_openModeCombo;

    // Whether enable heading sequence.
    QComboBox *m_headingSequenceTypeCombo;
    QComboBox *m_headingSequenceLevelCombo;

    // Color column in code block.
    VLineEdit *m_colorColumnEdit;
};

class VSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit VSettingsDialog(QWidget *p_parent = 0);

private slots:
    void saveConfiguration();

    void resetVNote();

    void resetLayout();

private:
    void loadConfiguration();

    void addTab(QWidget *p_widget, const QString &p_label);

    QStackedLayout *m_tabs;
    QListWidget *m_tabList;
    QDialogButtonBox *m_btnBox;

    // Reset all the configuration of VNote.
    QPushButton *m_resetVNoteBtn;

    // Reset the layout.
    QPushButton *m_resetLayoutBtn;
};

#endif // VSETTINGSDIALOG_H
