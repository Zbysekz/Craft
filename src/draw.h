/*
 * draw.h
 *
 *  Created on: 23. 3. 2018
 *      Author: ACZ2980
 */

#ifndef SRC_DRAW_H_
#define SRC_DRAW_H_


GLuint gen_crosshair_buffer();
GLuint gen_wireframe_buffer(float x, float y, float z, float n);
GLuint gen_sky_buffer();
GLuint gen_cube_buffer(float x, float y, float z, float n, int w);
GLuint gen_plant_buffer(float x, float y, float z, float n, int w);
GLuint gen_player_buffer(float x, float y, float z, float rx, float ry);
GLuint gen_bot_buffer(float x, float y, float z, float rx, float ry);
GLuint gen_text_buffer(float x, float y, float n, char *text);

void draw_triangles_3d_ao(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_3d_text(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_3d(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_2d(Attrib *attrib, GLuint buffer, int count);

void draw_lines(Attrib *attrib, GLuint buffer, int components, int count);
void draw_chunk(Attrib *attrib, Chunk *chunk);
void draw_item(Attrib *attrib, GLuint buffer, int count);
void draw_text(Attrib *attrib, GLuint buffer, int length);
void draw_signs(Attrib *attrib, Chunk *chunk);
void draw_sign(Attrib *attrib, GLuint buffer, int length);
void draw_cube(Attrib *attrib, GLuint buffer);
void draw_plant(Attrib *attrib, GLuint buffer);
void draw_player(Attrib *attrib, Player *player);
void draw_bot(Attrib *attrib, Bot *bot);



int render_chunks(Attrib *attrib, Player *player);
void render_signs(Attrib *attrib, Player *player);
void render_sign(Attrib *attrib, Player *player);
void render_players(Attrib *attrib, Player *player);
void render_bots(Attrib *attrib);
void render_sky(Attrib *attrib, Player *player, GLuint buffer);
void render_wireframe(Attrib *attrib, Player *player);
void render_crosshairs(Attrib *attrib);
void render_item(Attrib *attrib);
void render_text(
    Attrib *attrib, int justify, float x, float y, float n, char *text);

#endif /* SRC_DRAW_H_ */
