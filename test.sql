drop table user;
drop table book;
drop table rental;

CREATE TABLE user(
    id varchar(30) NOT NULL,
    pw varchar(30) NOT NULL,
    name varchar(30) NOT NULL,
    tel varchar(30) NOT NULL,
    book Integer NOT NULL,
    overdue Integer NOT NULL,
    primary key(id)
);

CREATE TABLE book (
    title varchar(30) NOT NULL,
    author varchar(30) NOT NULL,
    publisher varchar(30) NOT NULL,
    isbn varchar(30) NOT NULL,
    quantity integer NOT NULL,
    PRIMARY KEY(isbn)
);

CREATE TABLE rental(
    user_id varchar(30) NOT NULL,
    title varchar(30) NOT NULL,
    author varchar(30) NOT NULL,
    publisher varchar(30) NOT NULL,
    isbn varchar(30) NOT NULL,
    rentalday date NOT NULL,
    returnday date NOT NULL
);