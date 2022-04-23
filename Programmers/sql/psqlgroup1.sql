SELECT ANIMAL_TYPE, COUNT(`ANIMAL_TYPE`) 
    FROM ANIMAL_INS GROUP BY ANIMAL_TYPE
        ORDER BY `ANIMAL_TYPE`;

 -- CAT이 먼저 나와야하는데 이것이 알파벳 먼저니 order by 를 animal_type으로 처리하면 된다