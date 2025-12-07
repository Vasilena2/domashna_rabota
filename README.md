# Проект: Библиотека (Library System)

## Описание

Проектът **„Библиотека“** представлява малка C++ система, която моделира работата на библиотека чрез няколко взаимосвързани класа — `Book`, `Author`, `Member`, `Loan` и `Library`. 
Той демонстрира прилагането на основни обектно-ориентирани концепции в C++:

- конструктори и деструктори;
- капсулация и достъп чрез getters и setters;
- `const`-коректност и валидация на данни;
- работа с вектори и асоциирани обекти;
- добри ООП практики в реалистичен контекст.

---

## Структура на проекта

```
Библиотека/
├── Author.h
├── Author.cpp
├── Book.h
├── Book.cpp
├── Member.h
├── Member.cpp
├── Loan.h
├── Loan.cpp
├── Library.h
├── Library.cpp
├── main.cpp
└── README.md
```

---

## Компилация и изпълнение

Отворете терминал в директорията на проекта и изпълнете:

```powershell
g++ -std=c++17 -Wall -Wextra -O2 main.cpp Book.cpp Author.cpp Member.cpp Loan.cpp Library.cpp -o main
```

След това стартирайте програмата (Windows PowerShell):

```powershell
.\main
```

или в Unix-подобна среда:

```bash
./main
```

---

## Примерен изход

```
Library: City Library
Total books: 5
Total members: 2
Active loans: 2
Books by J.K. Rowling:
  - Harry Potter and the Philosopher's Stone (1997)
  - Harry Potter and the Chamber of Secrets (1998)
Books currently on loan:
  - Harry Potter and the Philosopher's Stone (to Ivan Ivanov)
  - The Hobbit (to Maria Petrova)
```

---

## Класове

### Клас `Book`

Представя книга с основни характеристики.

**Членове:**
- `std::string title` — заглавие
- `Author author` — автор
- `int year` — година на издаване
- `std::string isbn` — ISBN номер
- `bool isLoaned` — дали книгата е заета

**Методи:**
- `Book(std::string t, Author a, int y, std::string i)` — параметризиран конструктор
- `setLoaned(bool l)` — задава статуса на заетост
- `to_string()` — връща текстово описание на обекта

---

### Клас `Author`

Представя автор на книги.

**Членове:**
- `std::string name` — име на автора
- `std::string nationality` — националност

**Методи:**
- `Author(std::string n, std::string nat)` — конструктор
- `to_string()` — текстово представяне

---

### Клас `Member`

Представя член на библиотеката.

**Членове:**
- `std::string name` — име
- `int memberId` — уникален номер

**Методи:**
- `Member(std::string n, int id)` — конструктор
- `to_string()` — текстово представяне

---

### Клас `Loan`

Представя заем на книга от член.

**Членове:**
- `Book* book` — указател към книгата
- `Member* member` — указател към члена
- `std::string date` — дата на заема

**Методи:**
- `Loan(Book* b, Member* m, std::string d)` — конструктор
- `to_string()` — текстово представяне

---

### Клас `Library`

Управлява колекцията от книги, членове и заеми.

**Членове:**
- `std::string name` — име на библиотеката
- `std::vector<Book>` — книги
- `std::vector<Member>` — членове
- `std::vector<Loan>` — заеми

**Методи:**
- `addBook(const Book& b)` — добавя книга
- `addMember(const Member& m)` — добавя член
- `loanBook(const std::string& isbn, int memberId, const std::string& date)` — заема книга
- `booksByAuthor(const std::string& authorName)` — книги от даден автор
- `activeLoans()` — текущи заеми
- `to_string()` — текстово представяне на библиотеката

---

## Образователни цели

Проектът има за цел да демонстрира:

- разделение между интерфейс (`.h`) и имплементация (`.cpp`);
- използване на списъци за инициализация;
- валидация и обработка на изключения;
- работа с вектори и асоциирани обекти;
- прилагане на const-коректност.
  
---
## Екранна снимка

<img width="1401" height="228" alt="image" src="https://github.com/user-attachments/assets/a391c19f-b3f5-456a-846c-2f149305297d" />
---

## Автор

**Име:** _Василена Маринова_  
**Номер:** _22305_  
**Курс:** Обектно-ориентирано програмиране (C++)  
**Дата:** _07/12/2025_


