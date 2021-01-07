let project = new Project('lua-test');

project.kore = false;

project.addFiles('Sources/**');
project.addIncludeDir("Sources");

project.addIncludeDir("Libraries/minilua");
project.addLib('dl');
project.setDebugDir('Deployment');

resolve(project);
