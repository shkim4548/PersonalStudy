﻿SELECT COUNT(DISTINCT NAME) FROM ANIMAL_INS
    WHERE ANIMAL_ID IS NOT NULL;

    -- COUNT를 하면서 동시에 중복을 제거하기 위해선 위처럼 사용한다.