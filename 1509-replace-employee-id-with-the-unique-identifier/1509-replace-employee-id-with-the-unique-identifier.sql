# Write your MySQL query statement below
select uni.unique_id, emp.name from Employees emp
Left join EmployeeUNI uni on uni.id=emp.id

     
-- INNER JOIN: Intersection only (common rows).
-- LEFT JOIN: Everything from left + intersection.
-- RIGHT JOIN: Everything from right + intersection.