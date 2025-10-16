# Write your MySQL query statement below
select name, bonus from Employee e
Left join Bonus b on b.empID=e.empID
where b.bonus<1000 or bonus is NULL