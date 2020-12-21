# Airplane-Seating-Registry
A warm-up exercise to get used to C++
<html>

- <b>nameGenerator.cpp</b> contains a function named <i>nameGenerator</i> that generates realistic names randomly from two arrays of first and last names.

- <b>airplane.cpp</b> contains a function named <i>Seating</i>. <br>

The user passes the desired number of rows, columns, and sections to the constructor of the Seating class during the creation of the registry object. The program will return a registry with random names assigned to the seats in the plane.

<br>

For 4 rows, 8 columns and 4 sections, the result should give an output similar to:
<br>
<br>
Airplane seating registry: 

+---------+---------+      +---------+---------+      +---------+---------+      +---------+---------+      
| 1A      | 1B      |      | 1C      | 1D      |      | 1E      | 1F      |      | 1G      | 1H      |      
| William | Richard |      | John    | Michael |      | David   | James   |      | Robert  | EMPTY   |      
| Anwar   | Caira   |      | Collins | Alic    |      | Bacon   | Colgan  |      | Ahlgren | EMPTY   |      
+---------+---------+      +---------+---------+      +---------+---------+      +---------+---------+      
| 2A      | 2B      |      | 2C      | 2D      |      | 2E      | 2F      |      | 2G      | 2H      |      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
+---------+---------+      +---------+---------+      +---------+---------+      +---------+---------+      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
+---------+---------+      +---------+---------+      +---------+---------+      +---------+---------+      
| 4A      | 4B      |      | 4C      | 4D      |      | 4E      | 4F      |      | 4G      | 4H      |      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
| EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      | EMPTY   | EMPTY   |      
+---------+---------+      +---------+---------+      +---------+---------+      +---------+---------+      
Number of seats: 32
Number of passengers: 7
Number of empty seats: 25
Number of rows: 4
Number of columns: 8
Number of sections: 4

<br>
<br>
<br>
The prompted number of columns should be a multiple of the number of sections for best results.
<br>
<i>However, there are times when the program fails and returns a std::bad_alloc exception, which will be fixed soon.</i>
</html>
