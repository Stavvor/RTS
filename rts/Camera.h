struct SCameraState {
	float minHeight = 0.5f;
	float maxHeight = 8.0f;
	vec3 pos; // pozycja kamery
	vec3 dir; // kierunek patrzenia (wektor jednostkowy)
	float speed; // mno¿nik zmian pozycji - "szybkoœæ" ruchów kamery
};