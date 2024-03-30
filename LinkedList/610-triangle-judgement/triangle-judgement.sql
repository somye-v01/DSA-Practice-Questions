# Write your MySQL query statement below
# create a new column altogether, then select everything

SELECT x,y,z,(
    CASE
        WHEN x+y<=z THEN "No"
        WHEN y+z<=x THEN "No"
        WHEN x+z<=y THEN "No"
        ELSE "Yes"
        END
) as triangle FROM Triangle;