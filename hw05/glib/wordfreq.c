/*
 * Compile with:
 * gcc wordfreq.c `pkg-config --cflags --libs glib-2.0`
 */
#include <glib.h>
#include <stdlib.h>

void print_key_value_pair(gpointer key, gpointer value, gpointer user_data){
    g_print(user_data, key, GPOINTER_TO_INT(value));
}

void print_frequencies(GHashTable *frequencies) {
    g_hash_table_foreach(frequencies, print_key_value_pair, "%s\t%d\n");
}


 
int main (void)
{
	gboolean worked;
	gchar *contents;
    gchar **words;
    GHashTable *frequencies;
	
	worked = g_file_get_contents("test_text.txt", &contents, NULL, NULL);
    if (!worked) {
        exit(1);
    }
    
    words = g_strsplit_set(contents, "?!-\"., \n", 0);

    frequencies = g_hash_table_new(g_str_hash, g_str_equal);
    guint length = g_strv_length(words);
    
    for (int i = 0; i < length; i++) {
        gchar *word = g_strstrip(words[i]);
        gint *freq = g_hash_table_lookup(frequencies, word);
        if (freq == NULL){
            g_hash_table_insert(frequencies, word, GINT_TO_POINTER(1));
        } else {
            g_hash_table_replace(frequencies, word, GINT_TO_POINTER(GPOINTER_TO_INT(freq)+ 1));
        }
    }
    
    g_hash_table_remove(frequencies, "");
    
    print_frequencies(frequencies);
    
    g_free(contents);
    g_strfreev(words);
    g_hash_table_destroy(frequencies);
    
    return 0;
}