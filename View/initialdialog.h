#ifndef INITIALDIALOG_H
#define INITIALDIALOG_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QCloseEvent>

class initialDialog : public QDialog
{
    Q_OBJECT
private:

    //layout principale
    QHBoxLayout* mainLayout;

    //layout dei pulsanti layout della descrizione del programma
    QVBoxLayout* buttonsLayout, *textImageLayout;

    //pulsante di avvio della vista senza dati
    QPushButton* newButton;

    //pulsante di avvio della vista ripristinando dati da un file
    QPushButton* openButton;

    //etichetta della descrizione del programma
    QLabel* text;

    /**
     * @brief addButtons:   aggiunge i pulsanti a buttonsLayout
     */
    void addButtons();

    /**
     * @brief addTextImage:   aggiunge testo e immagine a textImageLayout
     */
    void addTextImage();

    /**
     * @brief closeEvent:   consente la chiusura del dialog se avviene in modo esplicito, chiedendo ulteriore conferma
     * @param event:        evento di chiusura, è oggetto di valutazione sul fatto se sia generato dall'applicazione o da eventi esterni
     */
    void closeEvent(QCloseEvent *event) override;

private slots:

    /**
     * @brief closeWidget:  consente la chiusura del dialog; tale slot è collegato al click() del pulsante "newButton" e non è
     *                      collegato a "openButton" in quanto l'apertura di un file potrebbe non avere successo: in tal modo
     *                      l'utente può ritornare nel dialog iniziale.
     */
    void closeWidget();
public:

    /**
     * @brief initialDialog         costruttore del dialog: serve a gestire la prima interazione dell'utente con la vista
     * @param parent:               widget genitore di tale dialog
     */
    explicit initialDialog(QWidget *parent = nullptr);

signals:
    void openFile() const;
    void showView() const;
    void closeAll() const;
};

#endif // INITIALDIALOG_H
