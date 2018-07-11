#ifndef NCURSESPROMPT_H
#define NCURSESPROMPT_H

#define __USE_XOPEN
#include <wchar.h>
#define _XOPEN_SOURCE_EXTENDED
#include <ncursesw/ncurses.h>

struct prompt_info
{
  wchar_t *text;
  size_t allocated;
  size_t offset;
  size_t cursor;
  int active;
};

struct prompt_info *prompt_info_alloc(size_t initial_size);
void free_prompt_info(struct prompt_info *info);
int format_prompt(struct prompt_info *prompt, wchar_t *format, ...);
void set_prompt_active_state(struct prompt_info *prompt, int active);
void update_prompt(WINDOW *promptwin, struct prompt_info *prompt, wchar_t *commandbuffer, int cursor_delta);
void print_prompt(WINDOW *promptwin, struct prompt_info *prompt, wchar_t *commandbuffer);

#endif