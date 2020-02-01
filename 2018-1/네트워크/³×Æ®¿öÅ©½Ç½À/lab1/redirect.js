// 모듈을 추출합니다.
const express = require('express');
// 서버를 생성합니다.
const app = express();
// request 이벤트 리스너를 설정합니다.
app.get('*', (request, response) => {
    response.redirect('http://hanbit.co.kr');
});
// 서버를 실행합니다.
app.listen(8080, () => {
    console.log('Server running at http://127.0.0.1:8080');
});
