malloc의 생존기간은 free해줄떄까지 이므로
Score* totalScore(Score* p1, Score* p2) {

	Score score;



	score.midterm = p1->midterm + p2->midterm;

	score.final = p1->final + p2->final;



	return &score;

}

Score* createScore(int m, int f) {

	Score score;



	score.final = f;

	score.midterm = m;



	return &score;

}
Score는 지역 변수이기 때문에 동적할당을 사용해야한다.