var layoutIS = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};
var layoutIT = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};
var layoutOS = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};
var layoutOT = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};
var layoutOC = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};
var layoutOV = {
    xaxis: { title: 'Time', showticklabels: true },
    yaxis: { showticklabels: true },
    margin: { autosize: true, t: 0, b: 40, l: 30, r: 10 },
    hovermode: 'closest',
    showlegend: false
};

$(document).ready(function () {

    // Initialize plotly plots.
    Plotly.newPlot(inputSpeedGraph, [{ x: [], y: [] }], layoutIS);
    Plotly.newPlot(inputTorqueGraph, [{ x: [], y: [] }], layoutIT);
    Plotly.newPlot(outputSpeedGraph, [{ x: [], y: [] }], layoutOS);
    Plotly.newPlot(outputTorqueGraph, [{ x: [], y: [] }], layoutOT);
    Plotly.newPlot(outputCurrentGraph, [{ x: [], y: [] }], layoutOC);
    Plotly.newPlot(outputVoltageGraph, [{ x: [], y: [] }], layoutOV);
    inputSpeedGraph.syncZoomWith = [inputTorqueGraph];
    inputTorqueGraph.syncZoomWith = [inputSpeedGraph];
    outputSpeedGraph.syncZoomWith = [outputTorqueGraph, outputCurrentGraph, outputVoltageGraph];
    outputTorqueGraph.syncZoomWith = [outputSpeedGraph, outputCurrentGraph, outputVoltageGraph];
    outputCurrentGraph.syncZoomWith = [outputSpeedGraph, outputTorqueGraph, outputVoltageGraph];
    outputVoltageGraph.syncZoomWith = [outputSpeedGraph, outputTorqueGraph, outputCurrentGraph];
    inputSpeedGraph.once('plotly_relayout', updateZoom.bind(inputSpeedGraph));
    inputTorqueGraph.once('plotly_relayout', updateZoom.bind(inputTorqueGraph));
    outputSpeedGraph.once('plotly_relayout', updateZoom.bind(outputSpeedGraph));
    outputTorqueGraph.once('plotly_relayout', updateZoom.bind(outputTorqueGraph));
    outputCurrentGraph.once('plotly_relayout', updateZoom.bind(outputCurrentGraph));
    outputVoltageGraph.once('plotly_relayout', updateZoom.bind(outputVoltageGraph));

    // Lock timescales of input graphs, and output graphs.
    function updateZoom(eventdata) {

        // Determine which properties to update.
        var update = {};
        if (typeof eventdata['xaxis.range[0]'] === 'number') {
            update = {
                'xaxis.range': [eventdata['xaxis.range[0]'], eventdata['xaxis.range[1]']]
            };
        } else if (eventdata['xaxis.autorange'] != undefined) {
            update = {
                'xaxis.autorange': true,
                'yaxis.autorange': true
            };
        } else if (eventdata['xaxis.showspikes'] != undefined) {
            update = {
                'xaxis.showspikes': eventdata['xaxis.showspikes'],
                'yaxis.showspikes': eventdata['yaxis.showspikes']
            }
        } else if (eventdata['hovermode'] != undefined) {
            update = {
                'hovermode': eventdata['hovermode']
            }
        } else if (eventdata['dragmode'] != undefined) {
            update = {
                'dragmode': eventdata['dragmode']
            }
        }

        // Lock input graphs timescales.
        this.syncZoomWith.forEach(function (graph) {
            Plotly.relayout(graph, update)
        })

        // Prevent infinite looping due to asynchronity.
        setTimeout(function () {
            this.once('plotly_relayout', updateZoom.bind(this));
        }.bind(this), 100);
    };

    // Cause input dropdown to change text and which inputfields are visible.
    $(".dropdown-menu li a").click(function () {
        // Change dropdown text.
        $(this).parents(".dropdown").find('.dropdown-toggle').html($(this).text() + '<span class="caret"></span>');
        $(this).parents(".dropdown").find('.dropdown-toggle').val($(this).data('value'));

        // Determine which input was clicked.
        var input = $(this).parents(".panel")[0].id;

        // Hide all input field groups.
        $(this).parents(".panel").find('.const').hide();
        $(this).parents(".panel").find('.step').hide();
        $(this).parents(".panel").find('.ramp').hide();
        $(this).parents(".panel").find('.sine').hide();
        $(this).parents(".panel").find('.custom').hide();

        // Show the one that was selected.
        if ($(this).text() == "Constant") {
            $(this).parents(".panel").find('.const').show();
        }
        else if ($(this).text() == "Step") {
            $(this).parents(".panel").find('.step').show();
        }
        else if ($(this).text() == "Ramp") {
            $(this).parents(".panel").find('.ramp').show();
        }
        else if ($(this).text() == "Sinusoid") {
            $(this).parents(".panel").find('.sine').show();
        }
        else if ($(this).text() == "Custom") {
            $(this).parents(".panel").find('.custom').show();
            // Reset the graph.
            $(this).parents(".panel").find('#filename')[0].textContent = "Upload";
            if (input == "inputSpeed") {
                while (inputSpeedGraph.data.length > 0) {
                    Plotly.deleteTraces(inputSpeedGraph, 0);
                }
            } else if (input == "inputTorque") {
                while (inputTorqueGraph.data.length > 0) {
                    Plotly.deleteTraces(inputTorqueGraph, 0);
                }
            }
        }
        
        // Update plot.
        if ($(this).text() != "Custom") {
            updatePlotData($(this).text(), input);
        }
    });

    // Replot when input fields change.
    $(".input-field").change(function (event) {
        updatePlotData($(this).parents(".panel").find(".dropdown-toggle")[0].text, $(this).parents(".panel")[0].id);
    });

    // Replot when end time changes, unless custom on none is selected.
    $("#endtime").change(function (event) {
        var plotName = "inputSpeed";
        var plotType = document.getElementById(plotName).children[0].children[1].children[0].children[0].text;
        if (!plotType.includes("Custom") && !plotType.includes("Select Waveform")) {
            updatePlotData(plotType, plotName);
        }
        plotName = "inputTorque";
        plotType = document.getElementById(plotName).children[0].children[1].children[0].children[0].text;
        if (!plotType.includes("Custom") && !plotType.includes("Select Waveform")) {
            updatePlotData(plotType, plotName);
        }
    });

    // UNUSED: In place for if in the future, changing sample time in the model is possible.
    $("#sampletime").change(function (event) {
        var plotName = "inputSpeed";
        var plotType = document.getElementById(plotName).children[0].children[1].children[0].children[0].text;
        if (!plotType.includes("Custom") && !plotType.includes("Select Waveform")) {
            updatePlotData(plotType, plotName);
        }
        plotName = "inputTorque";
        plotType = document.getElementById(plotName).children[0].children[1].children[0].children[0].text;
        if (!plotType.includes("Custom") && !plotType.includes("Select Waveform")) {
            updatePlotData(plotType, plotName);
        }
    });

})

$(window).resize(function () {

    // Cause plots to resize on window size change.
    Plotly.Plots.resize(inputSpeedGraph);
    Plotly.Plots.resize(inputTorqueGraph);
    Plotly.Plots.resize(outputCurrentGraph);
    Plotly.Plots.resize(outputTorqueGraph);
    Plotly.Plots.resize(outputSpeedGraph);
    Plotly.Plots.resize(outputVoltageGraph);

});

// Trigger the submit input.
function clickUpload(event) {
    $(event.path[3].children.upload).trigger('click');
};

// When the file input changes, call this.
var openFile = function (event) {
    event.preventDefault();
    if (event.path[0].files.length > 0) {
        var f = event.path[0].files[0];
        UploadFile(f, event.path[5].id);
        event.path[0].value = "";
    }
    // Unused .xls / .xlsx parser.
    //var f = event.path[0].files[0];
    //var reader = new FileReader();
    //var name = f.name;
    //var plotData = [];
    //reader.onload = function (e) {
    //    var data = e.target.result;
    //    var workbook = XLSX.read(data, { type: 'binary' });
    //    var i = 2;
    //    var cellA = "A" + i;
    //    var cellB = "B" + i;
    //    var Sheet = workbook.Sheets[workbook.SheetNames[0]];
    //    while (Sheet[cellA] !== undefined && Sheet[cellB] !== undefined) {
    //        plotData[i - 2] = [Sheet[cellA].v, Sheet[cellB].v];
    //        i++;
    //        var cellA = "A" + i;
    //        var cellB = "B" + i;
    //    }
    //};
    //reader.readAsBinaryString(f);
    //
    //reader.onloadend = function (e) {
    //    var id = event.path[4].id;
    //    if (id == "inputSpeed") {
    //        refSpeedPlot.series[0].data = plotData;
    //        refSpeedPlot.replot({ resetAxes: true });
    //    }
    //    if (id == "inputTorque") {
    //        loadTorquePlot.series[0].data = plotData;
    //        loadTorquePlot.replot({ resetAxes: true });
    //    }
    //}
};