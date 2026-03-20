# ===== CONFIG =====
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu89 -pedantic -O2 -Iinclude -MMD -MP
LDFLAGS = -lGL -lGLU -lglut -lm

SRC_DIR = src
BUILD_DIR = build
EXEC = game

# ===== SOURCES =====
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(OBJ_FILES:.o=.d)

# ===== RULES =====
all: $(EXEC)

# Link
$(EXEC): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compile avec création automatique des dossiers
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Inclure automatiquement les dépendances des headers
-include $(DEP_FILES)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

re: clean all

.PHONY: all clean re