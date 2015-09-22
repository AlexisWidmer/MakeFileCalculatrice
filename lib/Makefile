#Les variables automatiques :
#$@ valeur du  target
#$< nom du premier pré-requis associé au target
#$? nom des pré-requis plus récent que le target
#$^ liste sans répétition des pré-requis
#$+ comme $^ mais avec les répétitions
#$* nom du target avec le suffix tronqué

#Variables pour faciliter la saisie et les modifications dans le Makefile :
#Variable pour le compilateur
CC ?= gcc

#Variables pour la confection de la librairie :
#Dossiers contenant les fichiers objets
DIROBJ = ../build/

#Dossiers contenant les bibliothèques et les executables
DIREXE = ../bin/

#Options pour les lignes de code faites pour la confection des fichiers objets
CFLAGS += -fPIC -Wall -I$(INCLUDEDIR)
OBJETS = $(DIROBJ)addition.o $(DIROBJ)soustraction.o $(DIROBJ)multiplication.o $(DIROBJ)division.o
FICHIERSC = $(OBJETS:.o=.c)
INCLUDEDIR = ../include/

#Noms des librairies statiques et dynamiques
LINKNAME := maBibArithmetique
libSTATIC := lib$(LINKNAME).a
MAJEUR = .1
MINEUR = .0
CORRECTION = .0
SONAMECOURT := lib$(LINKNAME).so
SONAME := $(SONAMECOURT)$(MAJEUR)
REALNAME := $(SONAME)$(MINEUR)$(CORRECTION)

#Options pour les librairies
libCFLAGS = -shared -fPIC -Wl,-soname,
libLDFLAGS = -L.
libLDLIBS = -lc

#Options pour l'archive
ARFLAGS = rcs

#Conception du Makefile :
#Fabrication de la biblioth_que dynamique et de la statique
all: $(libSTATIC) $(REALNAME)

CD:
	cd 

DIR:
	mkdir ../bin ../build

#Fabrication du fichier objet addition.o
$(OBJETS): CFLAGS := $(CFLAGS)
$(OBJETS): DIR CD $(INCLUDEDIR)fonction.h

#Conception de l'archive pour la bibliothèque statique
$(libSTATIC)($(OBJETS)): ARFLAGS := $(ARFLAGS)
$(libSTATIC)($(OBJETS)): $(OBJETS)

#Règle pour appeler la conception de l'archive
$(libSTATIC): $(libSTATIC)($(OBJETS))

#Conception de la bibliothèque dynamique avec ses 2 liens symboliques
$(REALNAME): $(OBJETS)
	$(CC) $(libCFLAGS)$(SONAME) -o $(DIREXE)$@ $^
	ln -sf $@ $(SONAMECOURT)
	ln -sf $@ $(SONAME)

cleanDIR: cleanFICHERS
	-rmdir ../bin ../build

cleanFICHERS:
	-rm ../bin/* ../build/*