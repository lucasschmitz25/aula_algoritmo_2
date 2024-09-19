  METHOD is_pomodore.

    DATA: lv_reversed_word TYPE string,
          lv_word          TYPE string.

    CLEAR: lv_word.

    lv_word = word.

    " Remove espaços e converte para minúsculas
    TRANSLATE lv_word TO LOWER CASE.
    CONDENSE lv_word NO-GAPS.

    " Inverte a string
    me->reverse_string( EXPORTING word = lv_word
                        IMPORTING word_reversed = lv_reversed_word ).

    " Compara a string original com a invertida

    IF lv_reversed_word = lv_word.

      result = abap_true.

    ENDIF.
  ENDMETHOD.
