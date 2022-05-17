----------------------------------------------
--CREEZ BAZA DE DATE 
USE master
DROP DATABASE IF EXISTS POO

CREATE DATABASE POO

--SELECTEZ BAZA DE DATE

USE POO

----------------------------------------------
--CREEZ TABELELE.
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='DateConectare' AND xtype='U')
CREATE TABLE DateConectare
(
	IDUser int not null IDENTITY(1000,1) PRIMARY KEY,
	username varchar(20),
	parola varchar(257),
	Nume varchar(20),
	Prenume varchar(20)
)
---------------------------------------------
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Locatii' AND xtype='U')
CREATE TABLE Locatii
(
	IDLocatie int not null IDENTITY(1000,1) PRIMARY KEY,
	Nume varchar(40),
	NrCamere int,
	Stele int,
	Judet varchar(20),
	Descriere varchar(255)
)
---------------------------------------------
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Obiective' AND xtype='U')
CREATE TABLE Obiective
(
	IDObiectiv int not null IDENTITY(1000,1) PRIMARY KEY,
	Nume varchar(40),
	Judet varchar(20),
	Descriere varchar(255)
)
---------------------------------------------
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='MijTransport' AND xtype='U')
CREATE TABLE MijTransport
(
	IDTransport int not null IDENTITY(1000,1) PRIMARY KEY,
	Nume varchar(20),
	Viteza varchar(20),
	Descriere varchar(255)
)

----------------------------------------------
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Rezervari' AND xtype='U')
CREATE TABLE Rezervari
(
	IDRezervare int not null IDENTITY(1000,1) PRIMARY KEY,
	IDUser int FOREIGN KEY REFERENCES DateConectare(IDUser),
	IDLocatie int FOREIGN KEY REFERENCES Locatii(IDLocatie),
	LocatiiDS date,
	LocatiiDP date,
	TransportR varchar(20),
	TransportD date
)

------------------INSERT----------------------
---------------------------------------------
INSERT INTO DateConectare(username,parola,Nume,Prenume)
VALUES
('admin', '8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918','Administrator','Sistem' ),--pass: admin
('master', '9285827b8031a1dbe7d1d04eb8a08c8891ee424a8002cfc7dd2df3d82cbff611','John','117'),--pass: chief
('best', '5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8','Mocanu','Razvan'), --pass:password
('test', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3','Baluti','Cristian') --pass: 123
---------------------------------------------
INSERT INTO Locatii(Nume,NrCamere,Stele,Judet, Descriere)
VALUES
('Casa cu Flori', '15','2', 'Mehedinti', 'O casa extraordinara ce merita vizitata in orice perioada a anului.'),
('Casa cu Mere', '5', '3','Teleorman', 'O casa extraordinara ce merita vizitata in orice perioada a anului. In special cand se coc merele'),
('Casa cu Pere', '12', '5','Dolj', 'O casa extraordinara ce merita vizitata in orice perioada a anului.In special cand se coc perele.'),
('Vraja Dunarii', '15','2', 'Calarasi', 'Pensiune la marginea dunarii, o vedere de invidiat.'),
('Pensiunea 3 Narcise', '20', '3','Gorj', 'Un nemaipomenit popas pentru oricine e in cautarea unei locatii linistite.'),
('Hotel Delfin', '30', '4','Bucuresti', 'Un hotel de invidiat, ce se observa printre altele.')

---------------------------------------------
INSERT INTO Obiective(Nume,Judet, Descriere)
VALUES
('Bust Mihai Viteazu', 'Mehedinti', 'O statuie situata in centrul orasului Strehaia.'),
('Babele', 'Brasov', 'O formatiune naturala ce situata in apropierea varfului Baba Mare'),
('Cetate', 'Simleu', 'Un obiectiv ce merita vizitat in orice perioada a anului.'),
('Sabia lui Stefan cel Mare', 'Arad', 'Sabia unuia dintre cei mai mari domnitori ai Romaniei.'),
('Sfinxul', 'Brasov', 'O formatiune naturala asemanatoare cu Sfinxul egiptean.'),
('Cazino', 'Constanta', 'Un obiectiv proaspat renovat si amenajat din Constanta, de la marginea Marii Negre.')
---------------------------------------------
INSERT INTO MijTransport(Nume,Viteza, Descriere)
VALUES
('Avion', '500', 'Un mijloc de transport foarte rapid.'),
('Autobuz', '90', 'Un mijloc de transport nu foarte rapid.'),
('Tren', '120', 'Un mijloc de transport ok.')
---------------------------------------------
INSERT INTO Rezervari(IDUser,IDLocatie,LocatiiDS,LocatiiDP,TransportR,TransportD)
VALUES
('1002','1000', '07.20.1996', '07.27.1996','Autobuz','07.26.1996'),
('1001','1001', '07.15.2005', '07.23.2005','Tren','07.20.2005'),
('1002','1004', '01.20.2009', '01.27.2009','Avion','01-23-2009'),
('1003','1003', '09.25.2011', '09.30.2011','Autobuz','09.27.2011'),
('1003','1002', '12.05.2020', '12.20.2020','Tren','12.19.2020'),
('1002','1005', '10.20.2021', '10.25.2021','Avion','10-23-2021')

---------------------------------------------

