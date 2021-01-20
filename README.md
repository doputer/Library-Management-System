소개
---
- MFC를 활용한 도서 관리 시스템

기능 정의
---
[![이미지]()]()

개발 환경
---
- Visual Studio 2019 Community
- MySQL 8.0

실행 방법
---
1. Visual Studio에서 해당 프로젝트를 연다.
2. pch.h에서 DB_USER, DB_PASS 부분을 사용자의 DB에 맞게 수정한다.
```
#define DB_USER [사용자 DB 아이디] // Line 23
#define DB_PASS [사용자 DB 비밀번호] // Line 24
#define DB_NAME [사용자 DB 이름] // Line 25
```
3. test.sql 파일을 이용해서 DB 테이블을 생성한다.
4. IDE에서 빌드 후 실행
