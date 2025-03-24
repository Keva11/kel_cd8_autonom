Leírás
A Random Number Checker egy ROS 2 alapú alkalmazás, amely két node-ot tartalmaz:
----------------------------------------------------------------------------------------
Random Number Publisher: Véletlenszámokat generál, és azokat egy topic-on keresztül publikálja.

Number Checker Subscriber: A véletlenszámokat figyeli, és ha a szám páros, kiírja, hogy "Even", ha páratlan, akkor "Odd".

A projekt célja, hogy bemutassa a ROS 2 node-ok és a topic-ok használatát, és gyakorlati tapasztalatot nyújtson a ROS 2 kommunikációs mechanizmusával kapcsolatban.

Telepítés
------------------------------------------------------------------
1. Lépj a ROS 2 workspace-be
Ha még nem rendelkezel workspace-tel, hozd létre a következő parancsokkal:


cd ~/ros2_ws/src

----------------------------------------
2. Repository klónozása
Klónozd a projekt repository-ját:


git clone https://github.com/Felhasznalonev/random_number_checker.git

---------------------------------------------------------------------
3. Workspace buildelése
Lépj vissza a workspace gyökérmappájába, és építsd meg a csomagot:


cd ~/ros2_ws
colcon build --packages-select random_checker
source install/setup.bash

Futtatás
--------------------------------------------
1. Random Number Publisher (Véletlenszám generáló)
Indítsd el a véletlenszám generáló node-ot:


ros2 run random_checker random_number_publisher

------------------------------------------------------
2. Number Checker Subscriber (Páros/Páratlan szám ellenőrző)
Indítsd el a szám ellenőrző node-ot:


ros2 run random_checker number_checker_subscriber

---------------------------------------------------------------
3. Launch fájl használata
A launch fájl egyszerre indítja el a két node-ot, ha nem szeretnéd külön-külön indítani őket:

ros2 launch random_checker random_number_launch.py

Felépítés
----------------------------
A rendszer két ROS 2 csomópontból (node) áll:

random_number_publisher:

Véletlenszámokat generál és közreadja azokat a /random_number topicon.

Véletlenszámok generálása történik egyenletes eloszlással 0-100 között.

number_checker_subscriber:

Feliratkozik a /random_number topicra.

Minden érkező számot ellenőriz, és kiírja, hogy "Even" vagy "Odd", attól függően, hogy páros vagy páratlan a szám.

Kódstruktúra
------------------------------------------------------------------------------
A csomag tartalmazza a következő fájlokat:

random_number_publisher.cpp: A véletlenszám generáló node.

number_checker_subscriber.cpp: A szám ellenőrző node.

random_number_launch.py: A launch fájl, amely egyszerre indítja el a két node-ot.

CMakeLists.txt és package.xml: A csomag build konfigurációs fájljai.

README.md: A dokumentációs fájl, amely tartalmazza a telepítési és futtatási lépéseket.
