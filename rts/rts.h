#pragma once
void attackCooldown(int);
void actionTimer(int);
void unitDetails(int);
void queueManager(int);
void posManager(int a);
void attackManager(int a);

void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnTimer(int);
void OnSpecialKeyPress(int key, int x, int y);
void OnSpecialKeyUp(int key, int x, int y);
void OnModifiedDown(unsigned char key, int i, int y);
void OnMouseKeyPress(int button, int state, int x, int y);
void OnMouseKeyUp(int button, int state, int x, int y);
void MouseCords(int x, int y);
void mouseWheel(int button, int dir, int x, int y);

void raycast(int x, int y, vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end);
void raycastEnd(int x, int y, vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end);
void moveEntities(const vector<shared_ptr<Unit>>& entities);

void renderBitmapString(float x, float y, void *font, int num);
void renderBitmapString(float x, float y, void *font, const char *string);
void drawHealth(float health);
void setOrthographicProjection();
void resetPerspectiveProjection();
void drawTxt(int x, int y, string txt);
void gameStatistics();


extern Player* player;
extern Game* game;
extern int w,h;
