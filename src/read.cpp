int read() {
	ifstream seting;
	seting.open("seting/seting.txt");
	seting >> player_s;
	seting >> bullet_s;
	seting >> enemy_volume;
	seting >> enemy_s;
	seting >> enemy_dist;
	int a = 0;
	return(a);
}