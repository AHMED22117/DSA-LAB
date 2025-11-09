#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    string name;
    int hp;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0) {
        name = n;
        hp = h;
        attack = a;
    }
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant c) {
        data = c;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->data.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node* remove(Node* root, string name) {
        if (!root) return NULL;
        if (name < root->data.name)
            root->left = remove(root->left, name);
        else if (name > root->data.name)
            root->right = remove(root->right, name);
        else {
            // Found the node
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data.name);
            }
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getFrontline(Node* root) {
        if (!root) return NULL;
        while (root->left)
            root = root->left;
        return root;
    }

    Node* getFrontline() {
        return getFrontline(root);
    }

    void displayInOrder(Node* root) {
        if (!root) return;
        displayInOrder(root->left);
        cout << root->data.name << "(" << root->data.hp << "HP) ";
        displayInOrder(root->right);
    }

    void displayTeam() {
        displayInOrder(root);
        cout << endl;
    }
};

class BattleQuest {
private:
    BST heroes;
    BST enemies;
    int round;

public:
    BattleQuest() {
        round = 1;
        srand(time(0));

        // Initialize heroes
        heroes.insert(Combatant("Arthur", 25, 6));
        heroes.insert(Combatant("Luna", 22, 5));
        heroes.insert(Combatant("Ragnar", 30, 7));
        heroes.insert(Combatant("Mira", 18, 4));
        heroes.insert(Combatant("Drake", 28, 6));

        // Initialize enemies
        enemies.insert(Combatant("Goblin", 20, 4));
        enemies.insert(Combatant("Orc", 25, 5));
        enemies.insert(Combatant("Troll", 30, 6));
        enemies.insert(Combatant("Viper", 18, 5));
        enemies.insert(Combatant("Wraith", 22, 5));
    }

    void showTeams() {
        cout << "\n=== Current Teams ===\n";
        cout << "Heroes: ";
        heroes.displayTeam();
        cout << "Enemies: ";
        enemies.displayTeam();
        cout << "=====================\n";
    }

    void startBattle() {
        cout << "\n??  BattleQuest: BST Arena ??\n";
        while (!heroes.isEmpty() && !enemies.isEmpty()) {
            cout << "\n===== ROUND " << round++ << " =====\n";
            showTeams();

            Node* hero = heroes.getFrontline();
            Node* enemy = enemies.getFrontline();

            if (!hero || !enemy)
                break;

            // Player attacks first
            int damage = hero->data.attack + (rand() % 5);
            enemy->data.hp -= damage;
            cout << hero->data.name << " attacks " << enemy->data.name
                 << " for " << damage << " damage!\n";

            if (enemy->data.hp <= 0) {
                cout << "?? " << enemy->data.name << " has been defeated!\n";
                enemies.remove(enemy->data.name);
                continue; // skip enemy's turn if dead
            }

            // Enemy counterattack
            damage = enemy->data.attack + (rand() % 5);
            hero->data.hp -= damage;
            cout << enemy->data.name << " counterattacks " << hero->data.name
                 << " for " << damage << " damage!\n";

            if (hero->data.hp <= 0) {
                cout << "?? " << hero->data.name << " has fallen!\n";
                heroes.remove(hero->data.name);
            }
        }

        // Game over
        if (heroes.isEmpty())
            cout << "\n?? All heroes defeated! Enemies win!\n";
        else
            cout << "\n?? All enemies defeated! Heroes win!\n";
    }
};

int main() {
    BattleQuest game;
    game.startBattle();
    return 0;
}
