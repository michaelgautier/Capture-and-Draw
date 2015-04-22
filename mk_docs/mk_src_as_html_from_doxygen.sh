reset

docs_dir=doxygen_docs
html_out_dir=src_as_html

rm -r $docs_dir
mkdir $html_out_dir
rm $html_out_dir/*

doxygen

#Create inline CSS tag
echo "<style>" > $docs_dir/html/cssstarttag.txt
echo >> $docs_dir/html/cssstarttag.txt
echo "</style>" > $docs_dir/html/cssendtag.txt
echo >> $docs_dir/html/cssendtag.txt

#Create inline CSS
cat $docs_dir/html/cssstarttag.txt $docs_dir/html/doxygen.css $docs_dir/html/cssendtag.txt > $docs_dir/html/doxygeninlinecss.txt

#Merge inline CSS with HTML into output directory

filenames=(
	$docs_dir/html/gautier_core_8hpp-example.html
	$docs_dir/html/gautier_interaction_8cpp-example.html
	$docs_dir/html/gautier_interaction_8hpp-example.html
	$docs_dir/html/gautier_interaction_console_8cpp-example.html
	$docs_dir/html/gautier_interaction_console_8hpp-example.html
	$docs_dir/html/gautier_interaction_sfml_8cpp-example.html
	$docs_dir/html/gautier_interaction_sfml_8hpp-example.html
	$docs_dir/html/gautier_interaction_types_8hpp-example.html
	$docs_dir/html/gautier_json_mapping_8cpp-example.html
	$docs_dir/html/gautier_json_mapping_8hpp-example.html
	$docs_dir/html/gautier_program_8cpp-example.html
	$docs_dir/html/gautier_program_8hpp-example.html
	$docs_dir/html/gautier_program_domain_8cpp-example.html
	$docs_dir/html/gautier_program_domain_8hpp-example.html
	$docs_dir/html/gautier_program_models_8cpp-example.html
	$docs_dir/html/gautier_program_models_8hpp-example.html
	$docs_dir/html/main_8cpp-example.html
)

for src_filename in "${filenames[@]}"
do
	dest_filename="$html_out_dir/""${src_filename##*/}"

	touch tmp_file.txt

	head -n7 $src_filename >> tmp_file.txt

	cat $docs_dir/html/doxygeninlinecss.txt >> tmp_file.txt

	tail -n+12 $src_filename >> tmp_file.txt

	mv tmp_file.txt $dest_filename
	
done
