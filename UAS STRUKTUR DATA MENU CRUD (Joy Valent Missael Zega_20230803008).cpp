#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int year;
};

vector<Book> books;

struct User {
    string username;
    string password;
    bool isAdmin;
};

vector<User> users;

const string adminUsername = "adminJoylibrary";
const string adminPassword = "Joy2024";

void displayMenu(string role) {
    if (role == "admin") {
        cout << "Menu Admin:" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Update Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
    } else {
        cout << "Menu Pengguna:" << endl;
        cout << "1. Tampilkan Buku" << endl;
        cout << "2. Keluar" << endl;
    }
}

void createBook() {
    Book book;
    cout << "Masukkan ID buku: ";
    cin >> book.id;
    cout << "Masukkan judul buku: ";
    cin.ignore(); 
    getline(cin, book.title);
    cout << "Masukkan penulis buku: ";
    getline(cin, book.author);
    cout << "Masukkan tahun terbit buku: ";
    cin >> book.year;
    books.push_back(book);
    cout << "Buku berhasil ditambahkan!" << endl;
}

void displayBooks() {
    cout << "Daftar Buku:" << endl;
    for (const auto& book : books) {
        cout << "ID: " << book.id << ", Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << endl;
    }
}

void updateBook() {
    int id;
    cout << "Masukkan ID buku yang ingin diupdate: ";
    cin >> id;
    for (auto& book : books) {
        if (book.id == id) {
            cout << "Masukkan judul baru: ";
            cin.ignore(); 
            getline(cin, book.title);
            cout << "Masukkan penulis baru: ";
            getline(cin, book.author);
            cout << "Masukkan tahun terbit baru: ";
            cin >> book.year;
            cout << "Buku berhasil diupdate!" << endl;
            return;
        }
    }
    cout << "Buku tidak ditemukan!" << endl;
}

void deleteBook() {
    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Buku tidak ditemukan!" << endl;
}

int main() {
    string username, password, role;
    int choice;

    User adminUser;
    adminUser.username = adminUsername;
    adminUser.password = adminPassword;
    adminUser.isAdmin = true;
    users.push_back(adminUser);

    while (true) {
    	cout << " " << endl;
    	cout << "  JOY's LIBRARY  " << endl;
    	cout << " " << endl;
        cout << "Menu Masuk :" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            bool isLoggedIn = false;
            for (const auto& user : users) {
                if (user.username == username && user.password == password) {
                    role = user.isAdmin ? "admin" : "user";
                    isLoggedIn = true;
                    break;
                }
            }

            if (isLoggedIn) {
                while (true) {
                    displayMenu(role);
                    cout << "Masukkan pilihan: ";
                    cin >> choice;

                    if (role == "admin") {
                        if (choice == 1) {
                            createBook();
                        } else if (choice == 2) {
                            displayBooks();
                        } else if (choice == 3) {
                            updateBook();
                        } else if (choice == 4) {
                            deleteBook();
                        } else if (choice == 5) {
                            break;
                        } else {
                            cout << "Pilihan tidak valid!" << endl;
                        }
                    } else { 
                        if (choice == 1) {
                            displayBooks();
                        } else if (choice == 2) {
                            break;
                        } else {
                            cout << "Pilihan tidak valid!" << endl;
                        }
                    }
                }
            } else {
                cout << "Login gagal. Periksa kembali username dan password!" << endl;
            }
        } else if (choice == 2) {
            cout << "Daftar sebagai User baru..." << endl;
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            User newUser;
            newUser.username = username;
            newUser.password = password;
            newUser.isAdmin = false;
            users.push_back(newUser);

            cout << "Registrasi berhasil!" << endl;
        } else if (choice == 3) {
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
