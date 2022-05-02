----------------------------------------------
--CREEZ BAZA DE DATE 
USE master
DROP DATABASE IF EXISTS POO

CREATE DATABASE POO

--SELECTEZ BAZA DE DATE

USE POO

----------------------------------------------
--CREEZ TABELELE.
CREATE TABLE DateConectare
(
	IDUser int not null IDENTITY(1000,1) PRIMARY KEY,
	username varchar(20),
	parola varchar(20),
	Nume varchar(20),
	Prenume varchar(20)
)
----------------------------------------------
CREATE TABLE test
(
	IDUser int FOREIGN KEY REFERENCES DateConectare(IDUser),
	LocatiiR varchar(20),
	LocatiiDS date,
	LocatiiDP date,
	TransportR varchar(20),
	TransportD date
)
---------------------------------------------
------------------INSERT----------------------
--INSERT INTO Excursii(IDGhid,IDRezervare,IDRegiune,IDTransport,Distanta,DataExcursie,PretExcursie)
--VALUES

---------------------------------------------
INSERT INTO DateConectare(username,parola,Nume,Prenume)
VALUES
('admin', 'admin','Administrator','Sistem' ),
('master', 'chief','John','117'),
('best', 'password','Mocanu','Razvan'),
('test', '123','Baluti','Cristian')
---------------------------------------------
INSERT INTO test(LocatiiR,LocatiiDS,LocatiiDP,TransportR,TransportD)
VALUES
('Casa cu Flori', '07.20.1996', '07.27.1996','masina','07.25.1996')
---------------------------------------------

