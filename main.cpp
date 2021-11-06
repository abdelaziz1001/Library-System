#include <bits/stdc++.h>

using namespace std;
struct book{
    int id;
    string name;
    int quantity;
    vector<string> borrows;
};
struct user{
    string name;
    int national_id;
    vector<int> brrowed;
};
vector<book> all_books;
vector<user> all_users;

void run_system();
void menu();
void choice();
void do_choice(int ch);
void add_book();
void search_prefix();
void users_borrowed();
void print_books();
bool sort_name(book a, book b);
bool sort_id(book a, book b);
void listing_books_id();
void listing_books_name();
void add_user();
int find_user(string u);
void borrow_book();
void return_book();
void print_users();

int main()
{
    menu();
    while(1){
        choice();
    }
    return 0;
}

void menu(){
    cout << "Library Menu\n"
         << "1) add book\n"
         << "2) search books by prefix\n"
         << "3) Print how borrowed book by name\n"
         << "4) print library by id\n"
         << "5) print library by name\n"
         << "6) add user\n"
         << "7) user borrow book\n"
         << "8) user return book\n"
         << "9) print users\n"
         << "10)Exit\n";
}

void choice(){
    cout << "Enter your menu choice[1 - 10]: ";
    int ch;
    cin >> ch;
    do_choice(ch);
}

void do_choice(int ch){
    switch(ch){
    case 1:
        add_book();
        break;
    case 2:
        search_prefix();
        break;
    case 3:
        users_borrowed();
        break;
    case 4:
        listing_books_id();
        break;
    case 5:
        listing_books_name();
        break;
    case 6:
        add_user();
        break;
    case 7:
        borrow_book();
         break;
    case 8:
        return_book();
        break;
    case 9:
        print_users();
        break;
    case 10:
         exit(0);
    }
}

void add_book(){
    book bx;
    cout << "Enter book info: id && name && total quantity: ";
    cin >> bx.id >> bx.name >> bx.quantity;
    all_books.push_back(bx);
}

void search_prefix(){
    string s;
    cout << "Enter book name prefix: ";
    cin >> s;
    bool flag, f = true;
    int sz = all_books.size();
    for(int i = 0; i < sz; i++){
        flag = true;
        if(s.size() > all_books[i].name.size())
            continue;
        for(int y = 0; y < s.size(); y++){
            if(s[y] != all_books[i].name[y]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << all_books[i].name << endl;
            f = false;
        }

    }
    if(f)
        cout << "No books with such prefix\n";
}

void users_borrowed(){
    cout << "Enter book name: ";
    string s;
    cin >> s;
    bool flag = true;
    int sz = all_books.size();
    for(int i = 0; i < sz; i++){
        if(all_books[i].name == s){
            flag = false;
            if(all_books[i].borrows.size() == 0)
                cout << "No one borrowed this book\n";
            for(int y = 0; y < all_books[i].borrows.size(); y++){
                cout << all_books[i].borrows[y] << "\n";
            }
        }
    }
    if(flag)
        cout << "Invalid book name\n";
}

void print_books(){
    cout << "\n";
    int sz = all_books.size();
    for(int i = 0; i < sz; i++){
        cout << "id = " << all_books[i].id
             << " name = " << all_books[i].name
             << " quantity = " << all_books[i].quantity
             << " borrowed = " << all_books[i].borrows.size()
             << "\n";
    }
}

bool sort_id(book a, book b){
    return a.id < b.id;
}
void listing_books_id(){
    sort(all_books.begin(), all_books.end(), sort_id);
    print_books();
}

bool sort_name(book a, book b){
    return a.name < b.name;
}
void listing_books_name(){
    sort(all_books.begin(), all_books.end(), sort_name);
    print_books();
}

void add_user(){
    cout << "Enter user name & national id: ";
    user u;
    cin >> u.name >> u.national_id;
    all_users.push_back(u);
}

int find_user(string u){
    for(int i = 0; i < all_users.size(); i++){
        if(all_users[i].name == u)
            return i;
    }
}
void borrow_book(){
    string u, b;
    cout << "Enter user name and book name: ";
    cin >> u >> b;
    for(int i = 0; i < all_books.size(); i++){
        if(all_books[i].name == b){
            all_users[find_user(u)].brrowed.push_back(all_books[i].id);
            all_books[i].borrows.push_back(u);
            all_books[i].quantity--;
            break;
        }
    }
}

void return_book(){
    string u, b;
    cout << "Enter user name and book name: ";
    cin >> u >> b;
    for(int i = 0; i < all_books.size(); i++){
        if(all_books[i].name == b){
            auto it = all_books[i].borrows.begin();
            for(int y = 0; y < all_books[i].borrows.size(); y++){
                if(u == all_books[i].borrows[y]){
                    it = all_books[i].borrows.begin()+y;
                }
            }
            all_books[i].borrows.erase(it);
            all_books[i].quantity++;
            break;
        }
    }
}

void print_users(){
    for(int i = 0; i < all_users.size(); i++){
        cout << "user " << all_users[i].name
             << " id " << all_users[i].national_id
             << " borrowed books ids: ";
        for(int y = 0; y < all_users[i].brrowed.size(); y++){
            cout << all_users[i].brrowed[y] << " ";
        }
        cout << "\n";
    }
}
