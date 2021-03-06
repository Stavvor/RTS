struct SCameraState {
	float minX = 35.0f;
	float minZ = 35.0f;

	float maxX = 297.0f;
	float maxZ = 297.0f;

	float minHeight = 1.0f;
	float maxHeight = 25.0f;
	vec3 pos; // pozycja kamery
	vec3 dir; // kierunek patrzenia (wektor jednostkowy)
	float speed; // mno�nik zmian pozycji - "szybko��" ruch�w kamery
	SCameraState()
	{
		pos.x = 0.0f;
		pos.y = 3.75f;
		pos.z = 0.0f;
		dir.x = 1.0f;
		dir.y = -1.0f;
		dir.z = 1.0f;
		speed = .1f;
	}
};