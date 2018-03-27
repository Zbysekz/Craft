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


void check_workers();
void force_chunks(Player *player);
void ensure_chunks_worker(Player *player, Worker *worker);
void ensure_chunks(Player *player);

int worker_run(void *arg);

void gen_sign_buffer(Chunk *chunk);
int _gen_sign_buffer(GLfloat *data, float x, float y, float z, int face, const char *text);


void load_chunk(WorkerItem *item);

void request_chunk(int p, int q);

void init_chunk(Chunk *chunk, int p, int q);

void create_chunk(Chunk *chunk, int p, int q) ;

void delete_chunks();

void delete_all_chunks();



#define XZ_SIZE (CHUNK_SIZE * 3 + 2)
#define XZ_LO (CHUNK_SIZE)
#define XZ_HI (CHUNK_SIZE * 2 + 1)
#define Y_SIZE 258
#define XYZ(x, y, z) ((y) * XZ_SIZE * XZ_SIZE + (x) * XZ_SIZE + (z))
#define XZ(x, z) ((x) * XZ_SIZE + (z))

void light_fill(
    char *opaque, char *light,
    int x, int y, int z, int w, int force);

void compute_chunk(WorkerItem *item) ;

void generate_chunk(Chunk *chunk, WorkerItem *item);

void gen_chunk_buffer(Chunk *chunk);


void map_set_func(int x, int y, int z, int w, void *arg);


void dirty_chunk(Chunk *chunk) ;

void occlusion(char neighbors[27], char lights[27], float shades[27],
    float ao[6][4], float light[6][4]);



int has_lights(Chunk *chunk) ;



void unset_sign(int x, int y, int z) ;

void unset_sign_face(int x, int y, int z, int face);

void _set_sign(
    int p, int q, int x, int y, int z, int face, const char *text, int dirty);

void set_sign(int x, int y, int z, int face, const char *text);

void toggle_light(int x, int y, int z) ;

void set_light(int p, int q, int x, int y, int z, int w) ;

void _set_block(int p, int q, int x, int y, int z, int w, int dirty) ;

void set_block(int x, int y, int z, int w);

void record_block(int x, int y, int z, int w);

int get_block(int x, int y, int z) ;

void builder_block(int x, int y, int z, int w);


#endif /* SRC_DRAW_H_ */
