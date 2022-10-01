#include <iostream>

using namespace std;

class Book {
public:
	Book() {
		isAvailable = true;
	};
	Book(const string& name, const string& author, const string& publisher, const int& ISBN) {
		this->name = name;
		this->author = author;
		this->publisher = publisher;
		this->ISBN = ISBN;
		edition = 1;
		isAvailable = true;
	};
	Book(const string& name, const string& author, const string& publisher, const int& ISBN, const int& edition) {
		this->name = name;
		this->author = author;
		this->publisher = publisher;
		this->ISBN = ISBN;
		this->edition = edition;
		isAvailable = true;
	}

	void inputDetails() {
		cout << "Enter the name of a book: "; cin >> name;
		cout << "Enter the author of a book: "; cin >> author;
		cout << "Enter the publisher of a book: "; cin >> publisher;
		cout << "Enter the assignedCMS of a book: "; cin >> assignedCMS;
		cout << "Enter the ISBN of a book: "; cin >> ISBN;
		cout << "Enter the edition of a book: "; cin >> edition;
		cout << "Enter the isAvailable (1: true and 0: false) of a book"; cin >> isAvailable;
	}

	bool dispDetails(const string& Name_bookFun) {
		if (name == Name_bookFun) {
			cout << "Name: " << name
				<< "\nAuthor: " << author
				<< "\nPublisher: " << publisher
				<< "\nassignedCMS: " << assignedCMS
				<< "\nISBN: " << ISBN
				<< "\nEdition: " << edition
				<< "\nisAvailable: " << isAvailable;
			return true;
			
		}
		else
			return false;
	}

	bool dispDetails(const int& ISBNFun) {
		if (ISBN == ISBNFun) {
			cout << "Name: " << name
				<< "\nAuthor: " << author
				<< "\nPublisher: " << publisher
				<< "\nassignedCMS: " << assignedCMS
				<< "\nISBN: " << ISBN
				<< "\nEdition: " << edition
				<< "\nisAvailable: " << isAvailable;
			return true;

		}
		else
			return false;
	}

	bool dispDetails() {
		cout << "Name: " << name
			<< "\nAuthor: " << author
			<< "\nPublisher: " << publisher
			<< "\nassignedCMS: " << assignedCMS
			<< "\nISBN: " << ISBN
			<< "\nEdition: " << edition
			<< "\nisAvailable: " << isAvailable;
		return true;
	}

	bool availabilityStatus() {
		return isAvailable;
	}

	string issueBook(const string& cms) {
		assignedCMS = cms;
		isAvailable = false;
		return "Book is already issued to a student with CMS id " + cms;
	};

	// just to get the book name outside of class scope
	string get_book_name() const {
		return name;
	}

private:
	string name;
	string author;
	string publisher;
	string assignedCMS;
	// default values for int variables
	int ISBN{0};
	int edition{0};
	bool isAvailable;
};

class Library {
public:
	Library(const string& librarian) {
		maxBookNums = 100;
		currBooksNum = 0;
		this->librarian = librarian;
	};

	void dispBookDetails() {
		for (int i{ 0 }; i < currBooksNum; i++) {
			booksCollection[i].dispDetails();
		}
	}

	void addBook(const Book& bookObj) {
		booksCollection[currBooksNum] = bookObj;
		if (currBooksNum < maxBookNums)
			currBooksNum++;
	}
	void searchBook(const string& bookName) {
		for (int i{ 0 }; i < currBooksNum; i++) {
			if (booksCollection[i].get_book_name() == bookName)
				cout << "Availability status: " << booksCollection[i].availabilityStatus();
		}
	}
	// to know whether a book is present or not
	bool isBookPresent(const string& bookname) {
		for (int i{ 0 }; i < currBooksNum; i++) {
			if (booksCollection[i].get_book_name() == bookname)
				return true;
		}
		return false;
	}

	void assignBook(const string& cms_id, const string& book_name, Book bookObj) {
		if (!bookObj.availabilityStatus() || !isBookPresent(book_name)) {
			cout << bookObj.issueBook(cms_id);
		}
	}

private:
	string librarian;
	int maxBookNums;
	int currBooksNum;
	Book booksCollection[100];
};

int main() {
	// ...
	return 0;
}

