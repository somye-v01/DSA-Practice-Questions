/* Write your PL/SQL query statement below */
SELECT name,population,area FROM World
WHERE (population >= 25000000 OR area >= 3000000);
ORDER BY name desc