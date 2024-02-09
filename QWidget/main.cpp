#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QDebug>

class CharacterSheetApp : public QWidget {
public:
    CharacterSheetApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("D&D Character Sheet Customizer");

        QFormLayout *layout = new QFormLayout(this);

        nameEdit = new QLineEdit(this);
        raceEdit = new QLineEdit(this);
        classEdit = new QLineEdit(this);

        layout->addRow("Name:", nameEdit);
        layout->addRow("Race:", raceEdit);
        layout->addRow("Class:", classEdit);

        for (int i = 0; i < 6; ++i) {
            abilitySliders[i] = new QSlider(Qt::Horizontal, this);
            abilitySliders[i]->setMinimum(8); // Minimum value for each ability score
            abilitySliders[i]->setMaximum(18); // Maximum value for each ability score
            abilitySliders[i]->setValue(10); // Default value for each ability score
            layout->addRow(abilityLabels[i], abilitySliders[i]);
        }

        QPushButton *submitButton = new QPushButton("Submit", this);
        connect(submitButton, &QPushButton::clicked, this, &CharacterSheetApp::submit);
        layout->addWidget(submitButton);

    }

private slots:
    void submit() {
        QString name = nameEdit->text();
        QString race = raceEdit->text();
        QString charClass = classEdit->text();
        int strength = abilitySliders[0]->value();
        int dexterity = abilitySliders[1]->value();
        int constitution = abilitySliders[2]->value();
        int wisdom = abilitySliders[3]->value();
        int intelligence = abilitySliders[4]->value();
        int charisma = abilitySliders[5]->value();

        qDebug() << "Name: " << name;
        qDebug() << "Race: " << race;
        qDebug() << "Class: " << charClass;
        qDebug() << "Strength: " << strength;
        qDebug() << "Dexterity: " << dexterity;
        qDebug() << "Constitution: " << constitution;
        qDebug() << "Wisdom: " << wisdom;
        qDebug() << "Intelligence: " << intelligence;
        qDebug() << "Charisma: " << charisma;
    }
private:
    static const int MAX_ABILITY_POINTS = 90; // Maximum total points
    QLineEdit *nameEdit;
    QLineEdit *raceEdit;
    QLineEdit *classEdit;
    QSlider *abilitySliders[6];
    QLabel *abilityLabels[6] = {
        new QLabel("Strength (10)"),
        new QLabel("Dexterity (10)"),
        new QLabel("Constitution (10)"),
        new QLabel("Wisdom (10)"),
        new QLabel("Intelligence (10)"),
        new QLabel("Charisma (10)")
    };
    const QString abilityNames[6] = {"Strength", "Dexterity", "Constitution", "Wisdom", "Intelligence", "Charisma"};
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CharacterSheetApp window;
    window.resize(400, 300);
    window.show();

    return app.exec();
}
