-- SCHEME
-- Create table If Not Exists Employee (id int, salary int)
-- Truncate table Employee
-- insert into Employee (id, salary) values ('1', '100')
-- insert into Employee (id, salary) values ('2', '200')
-- insert into Employee (id, salary) values ('3', '300')


-- Solution 1

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

-- Solution 2
SELECT MAX(salary) as SecondHighestSalary FROM Employee
WHERE salary<(SELECT MAX(salary) FROM Employee) LIMIT 1;   