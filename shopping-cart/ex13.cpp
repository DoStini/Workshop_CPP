#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void readItems(vector<string> &listItems, vector<double> &prices)
{
    ifstream in("shoppingcart.txt");
    string listItem;
    double price;

    while (in >> listItem >> price)
    {
        listItems.push_back(listItem);
        prices.push_back(price);
    }
}

void writeItems(vector<string> listItems, vector<double> prices)
{
    ofstream out("shoppingcart.txt");

    for (int i = 0; i < listItems.size(); i++)
    {
        out << listItems.at(i) << " " << prices.at(i) << endl;
    }
}

double sumPrices(vector<double> prices)
{
    double sum = 0;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        sum += prices.at(i);
    }

    return sum;
}

void updateItem(vector<string> &listItems, vector<double> &prices)
{
    int id;
    double newPrice;
    string newItem;
    string oldItem;

    cout << "ID do item a atualizar: ";
    cin >> id;
    cin.ignore(10000, '\n');

    if (id < 0 || id > listItems.size())
    {
        cout << "Esse item não existe!" << endl;
        return;
    }

    oldItem = listItems.at(id - 1);

    cout << "Novo item: ";
    getline(cin, newItem);
    listItems.at(id - 1) = newItem;

    cout << "Novo preço (€): ";
    cin >> newPrice;
    prices.at(id - 1) = newPrice;

    cout << "Atualizado item " << oldItem << " para " << newItem << endl;
}

void printItems(vector<string> listItems, vector<double> prices)
{
    int size = listItems.size();
    double total = sumPrices(prices);

    cout << "ITENS NA LISTA DE COMPRAS" << endl;

    if (size == 0)
    {
        cout << "A lista de compras está vazia!" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " - " << listItems.at(i) << " - " << prices.at(i) << "€" << endl;
    }

    cout << "Total: " << total << "€" << endl;
}

void addItem(vector<string> &listItems, vector<double> &prices)
{
    string newItem;
    double price;

    cout << "Novo Item: ";
    getline(cin, newItem);

    cout << "Preço (€): ";
    cin >> price;

    listItems.push_back(newItem);
    prices.push_back(price);

    cout << "Adicionado item: " << newItem << endl;
}

void removeItem(vector<string> &listItems, vector<double> &prices)
{
    int id;
    string item;

    cout << "ID do item a remover: ";
    cin >> id;

    if (id < 0 || id > listItems.size())
    {
        cout << "Esse item não existe!" << endl;
        return;
    }

    item = listItems.at(id - 1);
    listItems.erase(listItems.begin() + id - 1);
    prices.erase(prices.begin() + id - 1);

    cout << "Removido item: " << item << endl;
}

/*
    Imprime as opções disponíveis para o ecrã, pede a opção desejada pelo utilizador, 
    e chama o código responsável pela mesma.
*/
void printAndChooseOption(int &option, vector<string> &listItems, vector<double> &prices)
{
    vector<string> options{"Sair do programa", "Ver itens", "Adicionar item", "Atualizar item", "Remover item"};

    for (int i = 0; i < options.size(); i++)
    {
        cout << i << ". " << options.at(i) << endl;
    }

    cout << "Escolha uma opção (0-" << options.size() << "): ";

    cin >> option;
    cin.ignore(10000, '\n');
    cout << string(2, '\n');

    switch (option)
    {
    case 0:
        // TERMINAR O PROGRAMA
        cout << "Saindo do programa. Obrigado por escolher a nossa aplicação!" << endl;
        break;
    case 1:
        // VER ITENS
        printItems(listItems, prices);
        break;
    case 2:
        // ADICIONAR ITEM
        addItem(listItems, prices);
        break;
    case 3:
        // ATUALIZAR ITEMS
        updateItem(listItems, prices);
        break;
    case 4:
        // REMOVER ITEMS
        removeItem(listItems, prices);
        break;
    default:
        cout << "Opção não existente!" << endl;
        break;
    }
    cout << string(2, '\n');
}

int main()
{
    // DECLARAÇÂO DAS VARIÀVEIS PRINCIPAIS

    int option = -1;
    vector<string> listItems;
    vector<double> prices;
    string name;

    cout << "Bem-vindo à MyShoppingList!" << endl;
    cout << "Qual é o teu nome? ";
    getline(cin, name);
    cout << "Olá " << name << "!" << endl;

    readItems(listItems, prices);

    while (option != 0)
        printAndChooseOption(option, listItems, prices);

    writeItems(listItems, prices);

    return 0;
}
