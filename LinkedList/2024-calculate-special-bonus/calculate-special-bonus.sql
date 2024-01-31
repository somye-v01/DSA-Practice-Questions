/* Write your PL/SQL query statement below */
SELECT employee_id,
case WHEN MOD(employee_id,2) = 1 AND name NOT LIKE 'M%' THEN salary
ELSE 0
END
AS "bonus"
FROM Employees
ORDER BY employee_id;


