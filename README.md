# Tema-POO-Official
Tema de semerstru - POO


În cadrul temei am implementat următorul protocol


Log|username|password|

--connected|Nume|Prenume|

--denied

Reg|username|password|Nume|Prenume|

--created

--denied ---Exista deja utilizatorul

--username -Username prea scurt

--parola ---Parola prea scurta

--nume --Lipsa nume

Locatii| --Afisati toate locatiile

--NrLocatii|Nume1|NrCamere1|Stele1|Judet1|Nume2|NrCamere2|Stele2|Judet2|Nume3|NrCamere3|Stele3||Judet3|

Obiective| --Afisati toate obiectivele

--NrObiective|Nume1|Judet1|Nume2|Judet2|Nume3|Judet3|Nume4|Judet4|

Transport| --Afisati toate mijloacele de transport

--NrMijloace|Nume1|Viteza1|Nume2|Viteza2|Nume3|Viteza3|Nume4|Viteza4|

Istoric| --Istoric user conectat curent

--NrIntrari|NumeLocatie|DataSosire|DataPlecare|Transport|DataTransport|

--error --Userul nu are nicio rezervare facuta

DetaliiLoc|NumeLocatie| --Afisare detaliata a unei locatii

--Nume|NrCamere|Stele|Judet|Descriere|

DetaliiTran|NumeTransport| --Afisare detaliata a unei locatii

--Nume|Viteza|Descriere|

RLoc|NumeLocatie|DataSosire|DataPlecare|MijTransport|DataTransport| --Rezerva locatia pentru userul conectat

--good --Locatie rezervata

--locuri --Nu mai sunt locuri disponibile

--transport --data de transport nu e in intervalul ales

--data --data de plecare si cea de sosire sunt invers

AddLoc|NumeLocatie|NrCamere|Stele|Judet|Descriere| --Adaugare Locatie

--yes --Locatie adaugata

--nume --Nume prea scurt

--camere --Camere prea putine

--stele --Numar stele invalid

--judet --Nume judet prea scurt

--descriere --Descriere prea scurta

--no --Eroare

AddTrans|NumeTransport|Viteza|Descriere| --Adaugare Transport

--yes --Transport adaugat

--nume --Nume prea scurt

--viteza --viteza prea mica

--descriere --Descriere prea scurta

--no --Eroare

AddObj|NumeObiectiv|Judet|Descriere| --Adaugare Obiectiv

--yes --Obiectiv adaugat

--nume --Nume prea scurt

--judet --nume judet prea scurt

--descriere --Descriere prea scurta

--no --Eroare

DelLoc|NumeLocatie| --Stergere Locatie

--success --Succes la stergerea locatiei

--eroare --Eroare la stergere

DelTrans|NumeTransport| --Stergere Transport

--success --Succes la stergerea locatiei

--eroare --Eroare la stergere

DelObj|NumeObiectiv| --Stergere Obiectiv

--success --Succes la stergerea locatiei

--eroare --Eroare la stergere
